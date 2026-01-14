/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ROCKCHIP_PM_DOMAINS_H
#define __ROCKCHIP_PM_DOMAINS_H

#include <linux/device.h>

/* Stub header for mainline kernel - power domain coordination disabled */

static inline int rockchip_pmu_idle_request(struct device *dev, bool idle)
{
	return 0;
}

#endif /* __ROCKCHIP_PM_DOMAINS_H */
