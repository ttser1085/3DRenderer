#pragma once

#include "Utils/Tagged.h"

#include <Observer.h>

#include <vector>

namespace r3d {

using ByVal = NSLibrary::CByValue;
using ByRef = NSLibrary::CByReference;

template<typename T>
using ByAuto = NSLibrary::NSObserverDetail::AutoSendBy<T>;

template<typename T, typename SendBy = ByAuto<T>,
		 typename Tag = utils::DefaultTag>
using Sender = utils::Tagged<NSLibrary::CObservableData<T, SendBy>, Tag>;

template<typename T, typename SendBy = ByAuto<T>,
		 typename Tag = utils::DefaultTag>
using HotReceiver = utils::Tagged<NSLibrary::CHotInput<T, SendBy>, Tag>;

template<typename T, typename SendBy = ByAuto<T>,
		 typename Tag = utils::DefaultTag>
using ColdReceiver = utils::Tagged<NSLibrary::CColdInput<T, SendBy>, Tag>;

template<typename T, typename Tag = utils::DefaultTag>
class StreamSender : public Sender<std::vector<T>, ByRef, Tag> {
	using Base = Sender<std::vector<T>, ByRef, Tag>;

public:
	template<class... Args>
	void append(Args&&... args) {
		data_.emplace_back(std::forward<Args>(args)...);
	}

	void flush() { Base::set(std::exchange(data_, {})); }

private:
	std::vector<T> data_;
};

template<typename T, typename Tag = utils::DefaultTag>
using HotStreamReceiver = HotReceiver<std::vector<T>, ByRef, Tag>;

template<typename T, typename Tag = utils::DefaultTag>
using ColdStreamReceiver = ColdReceiver<std::vector<T>, ByRef, Tag>;

} // namespace r3d
