#pragma once

#include <Observer.h>

#include <vector>

namespace r3d {

template<typename T,
		 typename TSendBy = NSLibrary::NSObserverDetail::AutoSendBy<T>>
using Sender = NSLibrary::CObservableData<T, TSendBy>;

template<typename T,
		 typename TSendBy = NSLibrary::NSObserverDetail::AutoSendBy<T>>
using HotReceiver = NSLibrary::CHotInput<T, TSendBy>;

template<typename T,
		 typename TSendBy = NSLibrary::NSObserverDetail::AutoSendBy<T>>
using ColdReceiver = NSLibrary::CColdInput<T, TSendBy>;

template<typename T>
class StreamSender {
	using Output = Sender<std::vector<T>, NSLibrary::CByReference>;
	using Input = NSLibrary::CObserver<std::vector<T>, NSLibrary::CByReference>;

public:
	template<class... Args>
	void set(Args&&... args) {
		data_.emplace_back(std::forward<Args>(args)...);
	}

	void flush() { out_.set(std::exchange(data_, {})); }

	void subscribe(Input* in) { out_.subscribe(in); }

private:
	Output out_;
	std::vector<T> data_;
};

template<typename T>
using HotStreamReceiver =
	NSLibrary::CHotInput<std::vector<T>, NSLibrary::CByReference>;

template<typename T>
using ColdStreamReceiver =
	NSLibrary::CColdInput<std::vector<T>, NSLibrary::CByReference>;

} // namespace r3d
