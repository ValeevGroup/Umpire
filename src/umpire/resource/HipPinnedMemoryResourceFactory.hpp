//////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016-24, Lawrence Livermore National Security, LLC and Umpire
// project contributors. See the COPYRIGHT file for details.
//
// SPDX-License-Identifier: (MIT)
//////////////////////////////////////////////////////////////////////////////
#ifndef UMPIRE_HipPinnedMemoryResourceFactory_HPP
#define UMPIRE_HipPinnedMemoryResourceFactory_HPP

#include "umpire/resource/HipPinnedMemoryResource.hpp"
#include "umpire/resource/MemoryResourceFactory.hpp"

namespace umpire {
namespace resource {

class HipPinnedMemoryResourceFactory : public MemoryResourceFactory {
  bool isValidMemoryResourceFor(const std::string& name) noexcept final override;

  std::unique_ptr<resource::MemoryResource> create(const std::string& name, int id) final override;

  std::unique_ptr<resource::MemoryResource> create(const std::string& name, int id,
                                                   MemoryResourceTraits traits) final override;

  MemoryResourceTraits getDefaultTraits() final override;
};

} // end of namespace resource
} // end of namespace umpire

#endif // UMPIRE_HipPinnedMemoryResourceFactory_HPP
