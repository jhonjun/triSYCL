#ifndef TRISYCL_SYCL_INFO_DEVICE_HPP
#define TRISYCL_SYCL_INFO_DEVICE_HPP

/** \file The OpenCL SYCL device information parameters

    Ronan at Keryell point FR

    This file is distributed under the University of Illinois Open Source
    License. See LICENSE.TXT for details.
*/

#include "CL/sycl/id.hpp"
#include "CL/sycl/opencl_types.hpp"
#include "CL/sycl/info/param_traits.hpp"

namespace cl {
namespace sycl {

/** \addtogroup execution Platforms, contexts, devices and queues
    @{
*/

namespace info {

/** Type of devices

    To be used either to define a device type or to select more
    broadly a kind of device

    \todo To be moved in the specification from platform to device

    \todo Add opencl to the specification

    \todo there is no accelerator_selector and custom_accelerator
*/
enum class device_type : unsigned int {
  cpu,
  gpu,
  accelerator,
  custom,
  automatic,
  host,
  opencl,
  all
};


/** Device information descriptors

    From specs/latex/headers/deviceInfo.h in the specification

    \todo Should be unsigned int?
*/
enum class device : int {
  device_type,
  vendor_id,
  max_compute_units,
  max_work_item_dimensions,
  max_work_item_sizes,
  max_work_group_size,
  preferred_vector_width_char,
  preferred_vector_width_short,
  preferred_vector_width_int,
  preferred_vector_width_long_long,
  preferred_vector_width_float,
  preferred_vector_width_double,
  preferred_vector_width_half,
  native_vector_witdth_char,
  native_vector_witdth_short,
  native_vector_witdth_int,
  native_vector_witdth_long_long,
  native_vector_witdth_float,
  native_vector_witdth_double,
  native_vector_witdth_half,
  max_clock_frequency,
  address_bits,
  max_mem_alloc_size,
  image_support,
  max_read_image_args,
  max_write_image_args,
  image2d_max_height,
  image2d_max_width,
  image3d_max_height,
  image3d_max_widht,
  image3d_mas_depth,
  image_max_buffer_size,
  image_max_array_size,
  max_samplers,
  max_parameter_size,
  mem_base_addr_align,
  single_fp_config,
  double_fp_config,
  global_mem_cache_type,
  global_mem_cache_line_size,
  global_mem_cache_size,
  global_mem_size,
  max_constant_buffer_size,
  max_constant_args,
  local_mem_type,
  local_mem_size,
  error_correction_support,
  host_unified_memory,
  profiling_timer_resolution,
  endian_little,
  is_available,
  is_compiler_available,
  is_linker_available,
  execution_capabilities,
  queue_properties,
  built_in_kernels,
  platform,
  name,
  vendor,
  driver_version,
  profile,
  device_version,
  opencl_version,
  extensions,
  printf_buffer_size,
  preferred_interop_user_sync,
  parent_device,
  partition_max_sub_devices,
  partition_properties,
  partition_affinity_domain,
  partition_type,
  reference_count
};

enum class device_partition_property : int {
  unsupported,
  partition_equally,
  partition_by_counts,
  partition_by_affinity_domain,
  partition_affinity_domain_next_partitionable
};

enum class device_affinity_domain : int {
  unsupported,
  numa,
  L4_cache,
  L3_cache,
  L2_cache,
  next_partitionable
};

enum class device_partition_type : int {
  no_partition,
  numa,
  L4_cache,
  L3_cache,
  L2_cache,
  L1_cache
};

enum class local_mem_type : int {
  none,
  local,
  global
};

enum class fp_config : int {
  denorm,
  inf_nan,
  round_to_nearest,
  round_to_zero,
  round_to_inf,
  fma,
  correctly_rounded_divide_sqrt,
  soft_float
};

enum class global_mem_cache_type : int {
  none,
  read_only,
  write_only
};

enum class device_execution_capabilities : unsigned int {
  exec_kernel,
  exec_native_kernel
};


using device_fp_config = unsigned int;
using device_exec_capabilities = unsigned int;
using device_queue_properties = unsigned int;


/** Query the return type for get_info() on context stuff

    \todo To be implemented, return always void.
*/
TRISYCL_INFO_PARAM_TRAITS_ANY_T(info::device, void)
TRISYCL_INFO_PARAM_TRAITS(info::device::device_type, info::device_type)
TRISYCL_INFO_PARAM_TRAITS(info::device::local_mem_size, cl::sycl::cl_ulong)
TRISYCL_INFO_PARAM_TRAITS(info::device::max_compute_units, cl::sycl::cl_uint)
TRISYCL_INFO_PARAM_TRAITS(info::device::max_mem_alloc_size, cl::sycl::cl_ulong)
TRISYCL_INFO_PARAM_TRAITS(info::device::max_work_group_size, std::size_t)
TRISYCL_INFO_PARAM_TRAITS(info::device::max_work_item_sizes, cl::sycl::id<3>)
TRISYCL_INFO_PARAM_TRAITS(info::device::name, string_class)
TRISYCL_INFO_PARAM_TRAITS(info::device::profile, string_class)
TRISYCL_INFO_PARAM_TRAITS(info::device::vendor, string_class)

}
}
}

/*
    # Some Emacs stuff:
    ### Local Variables:
    ### ispell-local-dictionary: "american"
    ### eval: (flyspell-prog-mode)
    ### End:
*/

#endif // TRISYCL_SYCL_INFO_DEVICE_HPP
