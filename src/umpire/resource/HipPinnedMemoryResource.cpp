//////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016-22, Lawrence Livermore National Security, LLC and Umpire
// project contributors. See the COPYRIGHT file for details.
//
// SPDX-License-Identifier: (MIT)
//////////////////////////////////////////////////////////////////////////////
#include "umpire/resource/HipPinnedMemoryResource.hpp"

#include <memory>
#include <sstream>

#include "umpire/ResourceManager.hpp"
#include "umpire/util/Macros.hpp"

namespace umpire {
namespace resource {

HipPinnedMemoryResource::HipPinnedMemoryResource(Platform platform, const std::string& name, int id,
                                                 MemoryResourceTraits traits)
    : MemoryResource(name, id, traits), m_allocator{traits.granularity}, m_platform(platform)
{
}

void* HipPinnedMemoryResource::allocate(std::size_t bytes)
{
  void* ptr = m_allocator.allocate(bytes);

  UMPIRE_LOG(Debug, "(bytes=" << bytes << ") returning " << ptr);

  return ptr;
}

void HipPinnedMemoryResource::deallocate(void* ptr, std::size_t UMPIRE_UNUSED_ARG(size))
{
  UMPIRE_LOG(Debug, "(ptr=" << ptr << ")");

  m_allocator.deallocate(ptr);
}

bool HipPinnedMemoryResource::isAccessibleFrom(Platform p) noexcept
{
  if (p == Platform::hip || p == Platform::host)
    return true;
  else
    return false;
}

Platform HipPinnedMemoryResource::getPlatform() noexcept
{
  return m_platform;
}

} // end of namespace resource
} // end of namespace umpire
