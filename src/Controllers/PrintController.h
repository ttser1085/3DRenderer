#pragma once

#include "Communication.h"
#include "Messages/Tick.h"
#include "Utils/Overloaded.h"

#include <string>

namespace r3d {

class PrintController {
	using Event = std::variant<std::string, Tick>;

public:
	PrintController()
		: input_([this](const Event& event) {
			  utils::Visit(
				  event,
				  [this](const std::string& str) { output_.append(str); },
				  [this](const Tick&) { output_.flush(); });
		  }) {}

	ColdInput<Event>* input() { return &input_; }

	void subscribe(StreamInput<std::string>* input) {
		output_.subscribe(input);
	}

private:
	ColdInput<Event> input_;
	StreamOutput<std::string> output_;
};

} // namespace r3d
