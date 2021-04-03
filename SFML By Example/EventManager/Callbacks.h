#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <unordered_map>
#include <functional>
#include "EventDetails.h"

using Callbacks = std::unordered_map<std::string,
      		                     std::function<void(EventDetails*)>>;

#endif
