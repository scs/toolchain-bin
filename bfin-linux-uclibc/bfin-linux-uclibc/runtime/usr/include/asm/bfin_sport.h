/*
 * bfin_sport.h - userspace header for bfin sport driver
 *
 * Copyright 2004-2008 Analog Devices Inc.
 *
 * Licensed under the GPL-2 or later.
 */

#ifndef __BFIN_SPORT_H__
#define __BFIN_SPORT_H__


#define SPORT_MAJOR	237
#define SPORT_NR_DEVS	2

/* Sport mode: it can be set to TDM, i2s or others */
#define NORM_MODE	0x0
#define TDM_MODE	0x1
#define I2S_MODE	0x2

/* Data format, normal, a-law or u-law */
#define NORM_FORMAT	0x0
#define ALAW_FORMAT	0x2
#define ULAW_FORMAT	0x3

/* Function driver which use sport must initialize the structure */
struct sport_config {
	/* TDM (multichannels), I2S or other mode */
	unsigned int mode:3;

	/* if TDM mode is selected, channels must be set */
	int channels;		/* Must be in 8 units */
	unsigned int frame_delay:4;	/* Delay between frame sync pulse and first bit */

	/* I2S mode */
	unsigned int right_first:1;	/* Right stereo channel first */

	/* In mormal mode, the following item need to be set */
	unsigned int lsb_first:1;	/* order of transmit or receive data */
	unsigned int fsync:1;	/* Frame sync required */
	unsigned int data_indep:1;	/* data independent frame sync generated */
	unsigned int act_low:1;	/* Active low TFS */
	unsigned int late_fsync:1;	/* Late frame sync */
	unsigned int tckfe:1;
	unsigned int sec_en:1;	/* Secondary side enabled */

	/* Choose clock source */
	unsigned int int_clk:1;	/* Internal or external clock */

	/* If external clock is used, the following fields are ignored */
	int serial_clk;
	int fsync_clk;

	unsigned int data_format:2;	/* Normal, u-law or a-law */

	int word_len;		/* How length of the word in bits, 3-32 bits */
	int dma_enabled;
};

/* Userspace interface */
#define SPORT_IOC_MAGIC		'P'
#define SPORT_IOC_CONFIG	_IOWR('P', 0x01, struct sport_config)


#define SPORT_TCR1	0
#define	SPORT_TCR2	1
#define	SPORT_TCLKDIV	2
#define	SPORT_TFSDIV	3
#define	SPORT_RCR1	8
#define	SPORT_RCR2	9
#define SPORT_RCLKDIV	10
#define	SPORT_RFSDIV	11
#define SPORT_CHANNEL	13
#define SPORT_MCMC1	14
#define SPORT_MCMC2	15
#define SPORT_MTCS0	16
#define SPORT_MTCS1	17
#define SPORT_MTCS2	18
#define SPORT_MTCS3	19
#define SPORT_MRCS0	20
#define SPORT_MRCS1	21
#define SPORT_MRCS2	22
#define SPORT_MRCS3	23

#endif
