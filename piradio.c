#include <linux/kernel.h>
#include <linux/jiffies.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/string.h>
#include <linux/socket.h>
#include <linux/errno.h>
#include <linux/fcntl.h>
#include <linux/in.h>

#include <linux/uaccess.h>
#include <linux/io.h>

#include <linux/inet.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/skbuff.h>
#include <linux/ethtool.h>
#include <net/sock.h>
#include <net/checksum.h>
#include <linux/if_ether.h>	/* For the statistics structure. */
#include <linux/if_arp.h>	/* For ARPHRD_ETHER */
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/percpu.h>
#include <linux/net_tstamp.h>
#include <net/net_namespace.h>
#include <linux/u64_stats_sync.h>

//#include </usr/src/linux-5.14.1-1/include/linux/errno.h>
//#include </usr/src/linux-5.14.1-1/include/linux/fcntl.h>
//#include </usr/src/linux-5.14.1-1/include/linux/fs.h>
//#include </usr/src/linux-5.14.1-1/include/linux/in.h>
//#include <linux/init.h>
//#include <linux/interrupt.h>
//#include <linux/jiffies.h>
//#include </usr/src/linux-5.14.1-1/include/linux/kernel.h>
//#include </usr/src/linux-5.14.1-1/include/linux/module.h>
//#include "/usr/src/linux-5.14.1-1/include/linux/netdevice.h"
////#include <linux/netdevice.h>
//#include <linux/printk.h>
//#include </usr/src/linux-5.14.1-1/include/linux/socket.h>
//#include </usr/src/linux-5.14.1-1/include/linux/string.h>
//#include </usr/src/linux-5.14.1-1/include/linux/types.h>
//
//#include <linux/io.h>
//#include <linux/uaccess.h>
//
//#include <linux/etherdevice.h>
//#include </usr/src/linux-5.14.1-1/include/linux/ethtool.h>
//#include </usr/src/linux-5.14.1-1/include/linux/if_arp.h> /* For ARPHRD_ETHER */
//#include <linux/if_ether.h> /* For the statistics structure. */
//#include <linux/inet.h>
//#include </usr/src/linux-5.14.1-1/include/linux/ip.h>
//#include <linux/net_tstamp.h>
//#include <linux/percpu.h>
//#include <linux/skbuff.h>
//#include </usr/src/linux-5.14.1-1/include/linux/tcp.h>
//#include <linux/u64_stats_sync.h>
//#include <net/checksum.h>
//#include <net/net_namespace.h>
//#include <net/sock.h>

MODULE_LICENSE("Dual BSD/GPL");

struct net_device *dev;

int piradio_open(struct net_device *dev){
	netif_start_queue(dev);
	memcpy(dev->dev_addr, "\0SNUL0", ETH_ALEN);
	return 0;
}

int piradio_config(struct net_device *dev){
	return 0;
}

netdev_tx_t piradio_tx(struct sk_buff *skb, struct net_device *dev){
	printk(KERN_ALERT "Got TX packet! \n");
	return 0;
}

int piradio_ioctl(struct net_device *dev){
	return 0;
}

void piradio_stats(struct net_device *dev, struct rtnl_link_stats64 *storage){
	return;
}

int piradio_rebuild_header(struct net_device *dev){
	return 0;
}

int piradio_header(struct net_device *dev, void *addr){
	return 0;
}

int piradio_dev_init(struct net_device *dev){
	return 0;
}

static int piradio_cleanup(struct net_device *dev){
	netif_stop_queue(dev);
	return 0;
}

static const struct net_device_ops piradio_ops = {
	.ndo_open	 = piradio_open,
	.ndo_stop	 = piradio_cleanup,
	.ndo_init        = piradio_dev_init,
	.ndo_start_xmit  = piradio_tx,
	.ndo_get_stats64 = piradio_stats,
	.ndo_set_mac_address = piradio_header,
};

void ret_0 (struct net_device *dev){
	return;
}

//static const struct ethtool_ops piradio_ethtool_ops = {
//	.get_link		= ret_0,
//	.get_ts_info		= ret_0,
//};

//const struct header_ops eth_header_ops ____cacheline_aligned = {
//	.create		= ret_0,
//	.parse		= ret_0,
//	.cache		= ret_0,
//	.cache_update	= ret_0,
//	.parse_protocol	= ret_0,
//};



void piradio_setup(struct net_device *dev){
	ether_setup(dev);
	dev->mtu		= (64 * 1024);
	dev->hard_header_len	= ETH_HLEN;	/* 14	*/
	dev->min_header_len	= ETH_HLEN;	/* 14	*/
	dev->addr_len		= ETH_ALEN;	/* 6	*/
	dev->type		= ARPHRD_ETHER;	/* 0x0001*/
	dev->flags		= IFF_BROADCAST | IFF_NOARP;
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
		| NETIF_F_VLAN_CHALLENGED;
//	dev->ethtool_ops	= &piradio_ethtool_ops;
//	dev->header_ops		= &eth_header_ops;
	dev->netdev_ops		= &piradio_ops;
	dev->needs_free_netdev	= 1;
	dev->priv_destructor	= ret_0;
}
static int piradio_init(void)
{
	printk(KERN_ALERT "Hello World\n");

	int err;

	err = -ENOMEM;
	dev = alloc_netdev(0, "piradio", NET_NAME_UNKNOWN, piradio_setup);
	err = register_netdev(dev);
	if (err)
		goto out_free_netdev;

	return 0;
out_free_netdev:
	free_netdev(dev);
	return -1;

}

static void piradio_exit(void)
{
	printk(KERN_ALERT "Goodbye \n");
	unregister_netdev(dev);
//	free_netdev(dev);
}

module_init(piradio_init);
module_exit(piradio_exit);
