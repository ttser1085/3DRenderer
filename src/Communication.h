#pragma once

#include "Utils/Tagged.h"

#include <Observer.h>

#include <vector>

namespace r3d {

template<typename T,
		 typename TSendBy = NSLibrary::NSObserverDetail::AutoSendBy<T>,
		 typename Tag = utils::DefaultTag>
using Sender = utils::Tagged<NSLibrary::CObservableData<T, TSendBy>, Tag>;

template<typename T,
		 typename TSendBy = NSLibrary::NSObserverDetail::AutoSendBy<T>,
		 typename Tag = utils::DefaultTag>
using HotReceiver = utils::Tagged<NSLibrary::CHotInput<T, TSendBy>, Tag>;

template<typename T,
		 typename TSendBy = NSLibrary::NSObserverDetail::AutoSendBy<T>,
		 typename Tag = utils::DefaultTag>
using ColdReceiver = utils::Tagged<NSLibrary::CColdInput<T, TSendBy>, Tag>;

template<typename T, typename Tag = utils::DefaultTag>
class StreamSender
	: public Sender<std::vector<T>, NSLibrary::CByReference, Tag> {
	using Base = Sender<std::vector<T>, NSLibrary::CByReference, Tag>;

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
using HotStreamReceiver =
	HotReceiver<std::vector<T>, NSLibrary::CByReference, Tag>;

template<typename T, typename Tag = utils::DefaultTag>
using ColdStreamReceiver =
	ColdReceiver<std::vector<T>, NSLibrary::CByReference, Tag>;

} // namespace r3d
