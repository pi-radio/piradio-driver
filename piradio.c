#include </usr/src/linux-5.14.1-1/include/linux/errno.h>
#include </usr/src/linux-5.14.1-1/include/linux/fcntl.h>
#include </usr/src/linux-5.14.1-1/include/linux/fs.h>
#include </usr/src/linux-5.14.1-1/include/linux/in.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/jiffies.h>
#include </usr/src/linux-5.14.1-1/include/linux/kernel.h>
#include </usr/src/linux-5.14.1-1/include/linux/module.h>
#include "/usr/src/linux-5.14.1-1/include/linux/netdevice.h"
//#include <linux/netdevice.h>
#include <linux/printk.h>
#include </usr/src/linux-5.14.1-1/include/linux/socket.h>
#include </usr/src/linux-5.14.1-1/include/linux/string.h>
#include </usr/src/linux-5.14.1-1/include/linux/types.h>

#include <linux/io.h>
#include <linux/uaccess.h>

#include <linux/etherdevice.h>
#include </usr/src/linux-5.14.1-1/include/linux/ethtool.h>
#include </usr/src/linux-5.14.1-1/include/linux/if_arp.h> /* For ARPHRD_ETHER */
#include <linux/if_ether.h> /* For the statistics structure. */
#include <linux/inet.h>
#include </usr/src/linux-5.14.1-1/include/linux/ip.h>
#include <linux/net_tstamp.h>
#include <linux/percpu.h>
#include <linux/skbuff.h>
#include </usr/src/linux-5.14.1-1/include/linux/tcp.h>
#include <linux/u64_stats_sync.h>
#include <net/checksum.h>
#include <net/net_namespace.h>
#include <net/sock.h>

MODULE_LICENSE("Dual BSD/GPL");



int piradio_open(struct net_device *dev){
	memcpy(dev->dev_addr, "\0SNUL0", ETH_ALEN);

}

int piradio_close(){

}

int piradio_config(){

}

int piradio_tx(){

}

int piradio_ioctl(){

}

int piradio_stats(){

}

int piradio_rebuild_header(){

}

int piradio_header(){

}

int piradio_dev_init(){

}

static const struct net_device_ops piradio_ops = {
	.ndo_open	 = &piradio_open,
	.ndo_close	 = &piradio_close,
	.ndo_init        = piradio_dev_init,
	.ndo_start_xmit  = piradio_tx,
	.ndo_get_stats64 = piradio_stats,
	.ndo_set_mac_address = piradio_header,
};

int ret_0 (){

}

static const struct ethtool_ops piradio_ethtool_ops = {
	.get_link		= ret_0,
	.get_ts_info		= ret_0,
};

const struct header_ops eth_header_ops ____cacheline_aligned = {
	.create		= ret_0,
	.parse		= ret_0,
	.cache		= ret_0,
	.cache_update	= ret_0,
	.parse_protocol	= ret_0,
};

static int piradio_cleanup(struct net_device *dev){
	unregister_netdev(dev);
	free_netdev(dev);
	return 0;
}

static int piradio_setup(struct net_device *dev){
	ether_setup(dev);
	dev->mtu		= (64 * 1024);
	dev->hard_header_len	= ETH_HLEN;	/* 14	*/
	dev->min_header_len	= ETH_HLEN;	/* 14	*/
	dev->addr_len		= ETH_ALEN;	/* 6	*/
	dev->type		= ARPHRD_LOOPBACK;	/* 0x0001*/
	dev->flags		= IFF_LOOPBACK;
	dev->priv_flags		|= IFF_LIVE_ADDR_CHANGE | IFF_NO_QUEUE;
	netif_keep_dst(dev);
	dev->hw_features	= NETIF_F_GSO_SOFTWARE;
	dev->features		= NETIF_F_SG | NETIF_F_FRAGLIST
		| NETIF_F_GSO_SOFTWARE
		| NETIF_F_HW_CSUM
		| NETIF_F_RXCSUM
		| NETIF_F_SCTP_CRC
		| NETIF_F_HIGHDMA
		| NETIF_F_LLTX
		| NETIF_F_NETNS_LOCAL
		| NETIF_F_VLAN_CHALLENGED
		| NETIF_F_LOOPBACK;
	dev->ethtool_ops	= &piradio_ethtool_ops;
	dev->header_ops		= &eth_header_ops;
	dev->netdev_ops		= &piradio_ops;
	dev->needs_free_netdev	= 1;
	dev->priv_destructor	= &ret_0;
}
static int piradio_init(void)
{
	printk(KERN_ALERT "Hello World\n");
	struct net_device *dev;
	int err;

	err = -ENOMEM;
	dev = alloc_netdev(0, "piradio", NET_NAME_UNKNOWN, piradio_setup);
	return 0;
}

static void piradio_exit(void)
{
	printk(KERN_ALERT "Goodbye \n");
}

module_init(piradio_init);
module_exit(piradio_exit);
