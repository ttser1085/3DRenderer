#pragma once

#include <Observer.h>

#include <vector>

namespace r3d {

using ByVal = NSLibrary::CByValue;
using ByRef = NSLibrary::CByReference;

template<typename T>
using ByAuto = NSLibrary::NSObserverDetail::AutoSendBy<T>;

template<typename T, typename SendBy = ByAuto<T>>
using Output = NSLibrary::CObservableData<T, SendBy>;

template<typename T, typename SendBy = ByAuto<T>>
using Input = NSLibrary::CObserver<T, SendBy>;

template<typename T, typename SendBy = ByAuto<T>>
using HotInput = NSLibrary::CHotInput<T, SendBy>;

template<typename T, typename SendBy = ByAuto<T>>
using ColdInput = NSLibrary::CColdInput<T, SendBy>;

template<typename T>
class StreamOutput : private Output<std::vector<T>, ByRef> {
	using Base = Output<std::vector<T>, ByRef>;

public:
	using Base::subscribe;

	template<class... Args>
	void append(Args&&... args) {
		data_.emplace_back(std::forward<Args>(args)...);
	}

	void flush() { Base::set(std::exchange(data_, {})); }

private:
	std::vector<T> data_;
};

template<typename T>
using HotStreamInput = HotInput<std::vector<T>, ByRef>;

template<typename T>
using ColdStreamInput = ColdInput<std::vector<T>, ByRef>;

} // namespace r3d
