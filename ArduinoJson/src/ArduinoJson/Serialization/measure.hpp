// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include "./DummyWriter.hpp"

namespace ArduinoJson {
namespace Internals {

template <template <typename> class TSerializer, typename TSource>
size_t measure(const TSource &source) {
  DummyWriter dp;
  TSerializer<DummyWriter> serializer(dp);
  source.visit(serializer);
  return serializer.bytesWritten();
}

}  // namespace Internals
}  // namespace ArduinoJson
