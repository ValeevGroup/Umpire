////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016-20, Lawrence Livermore National Security, LLC and Umpire
// project contributors. See the COPYRIGHT file for details.
//
// SPDX-License-Identifier: (MIT)
////////////////////////////////////////////////////////////////////////////
#ifndef UMPIRE_device_allocator_helper_HPP
#define UMPIRE_device_allocator_helper_HPP

#include "umpire/DeviceAllocator.hpp"
#include <string.h>

namespace umpire {

/*
 * Const variables for the limit of unique DeviceAllocator
 * objects available at once.
 */
extern const int UMPIRE_TOTAL_DEV_ALLOCS_h;
__device__ extern const int UMPIRE_TOTAL_DEV_ALLOCS;

/*
 * Global arrays for both host and device which hold the
 * DeviceAllocator objects created.
 */
extern DeviceAllocator* UMPIRE_DEV_ALLOCS_h;
__device__ extern DeviceAllocator* UMPIRE_DEV_ALLOCS;

/*
 * Get the DeviceAllocator object specified by either the given
 * name or id.
 */
__device__ extern DeviceAllocator getDeviceAllocator(const char* name);
__device__ extern DeviceAllocator getDeviceAllocator(int id);

/*
 * Check if the DeviceAllocator object specified by either the 
 * given name or id currently exists.
 */
extern bool deviceAllocatorExists(int id);
extern bool deviceAllocatorExists(const char* name);

/*!
 * \brief Construct a new DeviceAllocator. Calls the private Device
 * Allocator constructor that records the associated id.
 *
 * \param allocator Allocator to build the DeviceAllocator from.
 * \param size Total size of the DeviceAllocator.
 */
extern DeviceAllocator makeDeviceAllocator(Allocator allocator, size_t size, const char* name);

/*
 * Destroy any DeviceAllocator objects currently in existence.
 * Deallocate any memory belonging to object about to be destroyed.
 */
extern void destroyDeviceAllocator();

/*
 * This macro ensures that the host and device global arrays
 * that keep track of the DeviceAllocator objects created are
 * synced up and pointing to each other.
 */
#define UMPIRE_SYNC_DEVICE_ALLOCATORS()                       \
{                                                             \
  cudaMemcpyToSymbol(umpire::UMPIRE_DEV_ALLOCS,         \
                    &umpire::UMPIRE_DEV_ALLOCS_h,       \
                    sizeof(umpire::DeviceAllocator*));        \
}

} // end of namespace umpire

#endif // UMPIRE_device_allocator_helper_HPP
