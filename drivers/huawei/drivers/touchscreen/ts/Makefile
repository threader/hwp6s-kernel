# Makefile for the irda drivers.
#

# Each configuration option enables a list of files.

obj-$(CONFIG_HUAWEI_FEATURE_TS)  += huawei_touchscreen.o
obj-$(CONFIG_HUAWEI_FEATURE_TS) += panel/
obj-$(CONFIG_HUAWEI_FEATURE_TS_TEST)  += huawei_touchscreen_test.o


ifeq ($(CONFIG_HUAWEI_FEATURE_TS_TEST),y)
EXTRA_CFLAGS += -DHUAWEI_TOUCHSCREEN_TEST
endif