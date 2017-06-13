#pragma once

#include "common.h"

// DriverEntry handles driver init
DRIVER_INITIALIZE DriverEntry;

// DriverUnload handles driver unload


// FilterAttach handles attaching an individual filter layer to a network device
FILTER_ATTACH FilterAttach;

// FilterDetach handles unloading an individual filter layer from a network device
FILTER_DETACH FilterDetach;

// FilterPause handles suspension of the filter layer on an individual network device
FILTER_PAUSE FilterPause;

// FilterRestart handles post-attach/post-pause start of a filter layer on an individual network device.
FILTER_RESTART FilterRestart;