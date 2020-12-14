/*
 * Copyright (c) 2018 MediaTek Inc.
 * Author: Hsin-Hsiung.Wang <hsin-hsiung.wang@mediatek.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/power_supply.h>

struct ac_data {
	struct power_supply_desc psd;
	struct power_supply *psy;
};

struct battery_data {
	struct power_supply_desc psd;
	struct power_supply *psy;
};

static enum power_supply_property ac_props[] = {
	POWER_SUPPLY_PROP_ONLINE,
};

static enum power_supply_property battery_props[] = {
	POWER_SUPPLY_PROP_STATUS,
	POWER_SUPPLY_PROP_HEALTH,
	POWER_SUPPLY_PROP_PRESENT,
	POWER_SUPPLY_PROP_CAPACITY,
	POWER_SUPPLY_PROP_CHARGE_COUNTER,
	POWER_SUPPLY_PROP_CHARGE_FULL,
	POWER_SUPPLY_PROP_CURRENT_NOW,
	POWER_SUPPLY_PROP_CURRENT_MAX,
	POWER_SUPPLY_PROP_VOLTAGE_MAX,
	POWER_SUPPLY_PROP_VOLTAGE_NOW,
	POWER_SUPPLY_PROP_VOLTAGE_AVG,
	POWER_SUPPLY_PROP_TEMP,
};

static int ac_get_property(struct power_supply *psy,
	enum power_supply_property psp, union power_supply_propval *val)
{
	int ret = 0;

	switch (psp) {
	case POWER_SUPPLY_PROP_ONLINE:
		val->intval = 1;
		break;
	default:
		ret = -EINVAL;
		break;
	}
	return ret;
}

static int battery_get_property(struct power_supply *psy,
	enum power_supply_property psp, union power_supply_propval *val)
{
	int ret = 0;

	switch (psp) {
	case POWER_SUPPLY_PROP_STATUS:
		val->intval = POWER_SUPPLY_STATUS_CHARGING;
		break;
	case POWER_SUPPLY_PROP_HEALTH:
		val->intval = POWER_SUPPLY_HEALTH_GOOD;
		break;
	case POWER_SUPPLY_PROP_PRESENT:
		val->intval = 0;
		break;
	case POWER_SUPPLY_PROP_CAPACITY:
		val->intval = 100;
		break;
	case POWER_SUPPLY_PROP_CHARGE_COUNTER:
	case POWER_SUPPLY_PROP_CHARGE_FULL:
		val->intval = 3000*1000;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_NOW:
	case POWER_SUPPLY_PROP_VOLTAGE_AVG:
		val->intval = 4200 * 1000;
		break;
	case POWER_SUPPLY_PROP_TEMP:
		val->intval = 25;
		break;
	case POWER_SUPPLY_PROP_CURRENT_NOW:
		val->intval = 100 * 1000;
		break;
	case POWER_SUPPLY_PROP_CURRENT_MAX:
		val->intval = 3000000;
		break;
	case POWER_SUPPLY_PROP_VOLTAGE_MAX:
		val->intval = 5000000;
		break;
	default:
		ret = -EINVAL;
		break;
	}
	return ret;
}

static struct ac_data ac_main = {
	.psd = {
		.name = "ac",
		.type = POWER_SUPPLY_TYPE_MAINS,
		.properties = ac_props,
		.num_properties = ARRAY_SIZE(ac_props),
		.get_property = ac_get_property,
		},
};

static struct battery_data battery_main = {
	.psd = {
		.name = "battery",
		.type = POWER_SUPPLY_TYPE_BATTERY,
		.properties = battery_props,
		.num_properties = ARRAY_SIZE(battery_props),
		.get_property = battery_get_property,
		},
};

static int __init mt_battery_init(void)
{
	ac_main.psy =
		power_supply_register(NULL, &ac_main.psd, NULL);
	if (IS_ERR(ac_main.psy)) {
		pr_debug("[%s] power_supply_register AC Fail !!\n", __func__);
		return -1;
	}

	battery_main.psy =
		power_supply_register(NULL, &battery_main.psd, NULL);
	if (IS_ERR(battery_main.psy)) {
		pr_debug("[%s] power_supply_register Battery Fail !!\n",
			__func__);
		return -1;
	}
	pr_debug("[%s] power_supply_register AC/Battery Success !!\n",
		__func__);

	return 0;
}
module_init(mt_battery_init);

static void __exit mt_battery_exit(void)
{
	power_supply_unregister(battery_main.psy);
}
module_exit(mt_battery_exit);

MODULE_DESCRIPTION("Dummy Battery Device Driver");
MODULE_LICENSE("GPL v2");
