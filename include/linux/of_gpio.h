/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * OF helpers for the GPIO API
 *
 * Copyright (c) 2007-2008  MontaVista Software, Inc.
 *
 * Author: Anton Vorontsov <avorontsov@ru.mvista.com>
 */

#ifndef __LINUX_OF_GPIO_H
#define __LINUX_OF_GPIO_H

#include <linux/compiler.h>
#include <linux/gpio/driver.h>
#include <linux/gpio.h>		/* FIXME: Shouldn't be here */
#include <linux/of.h>

struct device_node;

/*
 * This is Linux-specific flags. By default controllers' and Linux' mapping
 * match, but GPIO controllers are free to translate their own flags to
 * Linux-specific in their .xlate callback. Though, 1:1 mapping is recommended.
 */
enum of_gpio_flags {
	OF_GPIO_ACTIVE_LOW = 0x1,
	OF_GPIO_SINGLE_ENDED = 0x2,
	OF_GPIO_OPEN_DRAIN = 0x4,
	OF_GPIO_TRANSITORY = 0x8,
	OF_GPIO_PULL_UP = 0x10,
	OF_GPIO_PULL_DOWN = 0x20,
	OF_GPIO_PULL_DISABLE = 0x40,
};

#ifdef CONFIG_OF_GPIO

extern int of_get_named_gpio_flags(const struct device_node *np,
		const char *list_name, int index, enum of_gpio_flags *flags);


extern int of_get_named_gpio(const struct device_node *np,
			     const char *list_name, int index);

#else /* CONFIG_OF_GPIO */

#include <linux/errno.h>

/* Drivers may not strictly depend on the GPIO support, so let them link. */
static inline int of_get_named_gpio(const struct device_node *np,
                                   const char *propname, int index)
{
	return -ENOSYS;
}

/* Drivers may not strictly depend on the GPIO support, so let them link. */
static inline int of_get_named_gpio_flags(const struct device_node *np,
		const char *list_name, int index, enum of_gpio_flags *flags)
{
	if (flags)
		*flags = 0;

	return -ENOSYS;
}

#endif /* CONFIG_OF_GPIO */

/**
 * of_gpio_named_count() - Count GPIOs for a device
 * @np:		device node to count GPIOs for
 * @propname:	property name containing gpio specifier(s)
 *
 * The function returns the count of GPIOs specified for a node.
 * Note that the empty GPIO specifiers count too. Returns either
 *   Number of gpios defined in property,
 *   -EINVAL for an incorrectly formed gpios property, or
 *   -ENOENT for a missing gpios property
 *
 * Example:
 * gpios = <0
 *          &gpio1 1 2
 *          0
 *          &gpio2 3 4>;
 *
 * The above example defines four GPIOs, two of which are not specified.
 * This function will return '4'
 */
static inline int of_gpio_named_count(const struct device_node *np,
				      const char *propname)
{
	return of_count_phandle_with_args(np, propname, "#gpio-cells");
}

#endif /* __LINUX_OF_GPIO_H */
