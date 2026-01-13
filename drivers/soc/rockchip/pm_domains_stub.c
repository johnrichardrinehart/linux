// SPDX-License-Identifier: GPL-2.0
/*
 * Rockchip PM Domain stub exports for vendor MPP/NPU drivers
 *
 * These are stub implementations to satisfy symbol dependencies
 * for vendor drivers that expect these QoS and idle request functions.
 */

#include <linux/export.h>
#include <linux/errno.h>
#include <linux/device.h>
#include <soc/rockchip/pm_domains.h>

/* Forward declaration for IOMMU function not in pm_domains.h */
bool rockchip_iommu_is_enabled(struct device *dev);

/*
 * QoS (Quality of Service) stubs - vendor MPP driver expects these
 * In a full implementation, these would save/restore bus QoS settings
 * For now, we just return success as the drivers handle missing QoS gracefully
 */
int rockchip_save_qos(struct device *dev)
{
	return 0;  /* Success - no QoS to save */
}
EXPORT_SYMBOL(rockchip_save_qos);

int rockchip_restore_qos(struct device *dev)
{
	return 0;  /* Success - no QoS to restore */
}
EXPORT_SYMBOL(rockchip_restore_qos);

/*
 * PMU idle request stub - vendor MPP driver uses this
 * In a full implementation, this would request the PMU to idle/unidle a power domain
 * Returning -ENOTSUPP indicates the feature isn't available
 */
int rockchip_pmu_idle_request(struct device *dev, bool idle)
{
	return -ENOTSUPP;  /* Not supported in mainline */
}
EXPORT_SYMBOL(rockchip_pmu_idle_request);

/*
 * IOMMU enabled check stub - vendor NPU driver uses this
 * In a full implementation, this would check if IOMMU is active for the device
 * We return true as the mainline IOMMU driver handles enablement through standard APIs
 */
bool rockchip_iommu_is_enabled(struct device *dev)
{
	return true;  /* Assume IOMMU is managed through standard DMA/IOMMU APIs */
}
EXPORT_SYMBOL(rockchip_iommu_is_enabled);
