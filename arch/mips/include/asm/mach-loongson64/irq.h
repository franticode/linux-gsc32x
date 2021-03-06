/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_MACH_LOONGSON64_IRQ_H_
#define __ASM_MACH_LOONGSON64_IRQ_H_

#include <boot_param.h>

#ifdef CONFIG_CPU_LOONGSON3

#define NR_IRQS	(64 + 256)

#define LIOINTC_DEFAULT_PHYS_BASE	(LOONGSON3_REG_BASE + 0x1400)
#define MAX_PCH_PICS			16
#define LOONGSON_CPU_UART0_VEC		10 /* CPU UART0 */
#define LOONGSON_CPU_THSENS_VEC		14 /* CPU Thsens */
#define LOONGSON_CPU_HT0_VEC		16 /* CPU HT0 irq vector base number */
#define LOONGSON_CPU_HT1_VEC		24 /* CPU HT1 irq vector base number */

/* IRQ number definitions */
#define LOONGSON_LPC_IRQ_BASE		0
#define LOONGSON_LPC_LAST_IRQ		(LOONGSON_LPC_IRQ_BASE + 15)

#define MIPS_CPU_IRQ_BASE 		56
#define LOONGSON_LINTC_IRQ   		(MIPS_CPU_IRQ_BASE + 2) /* UART */
#define LOONGSON_BRIDGE_IRQ 		(MIPS_CPU_IRQ_BASE + 3) /* CASCADE */
#define LOONGSON_THSENS_IRQ 		(MIPS_CPU_IRQ_BASE + 4) /* CPU Thsens */
#define LOONGSON_TIMER_IRQ  		(MIPS_CPU_IRQ_BASE + 7) /* CPU Timer */
#define MIPS_CPU_LAST_IRQ 		(MIPS_CPU_IRQ_BASE + 7)

#define LOONGSON_GUEST_UART0_IRQ	66

#define LOONGSON_PCH_IRQ_BASE		64
#define LOONGSON_GUEST_PCH_IRQ_BASE	32
#define LOONGSON_PCH_LAST_IRQ		(LOONGSON_PCH_IRQ_BASE + 63)

#define LOONGSON_PCI_MSI_IRQ_BASE	(LOONGSON_PCH_IRQ_BASE + 64)
#define LOONGSON_PCI_MSI_LAST_IRQ	(LOONGSON_PCH_IRQ_BASE + 256)

#define LOONGSON_IRQ2VEC(irq)		(irq - LOONGSON_PCH_IRQ_BASE)
#define LOONGSON_VEC2IRQ(vec)		(vec + LOONGSON_PCH_IRQ_BASE) 

#define LOONGSON_HT1_CFG_BASE		loongson_sysconf.ht_control_base
#define LOONGSON_HT1_INT_VECTOR_BASE	(LOONGSON_HT1_CFG_BASE + 0x80)
#define LOONGSON_HT1_INT_EN_BASE	(LOONGSON_HT1_CFG_BASE + 0xa0)
#define LOONGSON_HT1_INT_VECTOR(n)	\
		LOONGSON3_REG32(LOONGSON_HT1_INT_VECTOR_BASE, 4 * (n))
#define LOONGSON_HT1_INTN_EN(n)		\
		LOONGSON3_REG32(LOONGSON_HT1_INT_EN_BASE, 4 * (n))
#define LOONGSON_HT1_INT_VECTOR64(n)	\
    		LOONGSON3_REG64(LOONGSON_HT1_INT_VECTOR_BASE, 8 * (n))
#define LOONGSON_HT1_INTN_EN64(n)	\
    		LOONGSON3_REG64(LOONGSON_HT1_INT_EN_BASE, 8 * (n))

#define LOONGSON_INT_ROUTER_OFFSET	0x1400
#define LOONGSON_INT_ROUTER_INTSTS	\
	  LOONGSON3_REG32(LOONGSON3_REG_BASE, LOONGSON_INT_ROUTER_OFFSET + 0x20)
#define LOONGSON_INT_ROUTER_INTEN	\
	  LOONGSON3_REG32(LOONGSON3_REG_BASE, LOONGSON_INT_ROUTER_OFFSET + 0x24)
#define LOONGSON_INT_ROUTER_INTENSET	\
	  LOONGSON3_REG32(LOONGSON3_REG_BASE, LOONGSON_INT_ROUTER_OFFSET + 0x28)
#define LOONGSON_INT_ROUTER_INTENCLR	\
	  LOONGSON3_REG32(LOONGSON3_REG_BASE, LOONGSON_INT_ROUTER_OFFSET + 0x2c)
#define LOONGSON_INT_ROUTER_ENTRY(n)	\
	  LOONGSON3_REG8(LOONGSON3_REG_BASE, LOONGSON_INT_ROUTER_OFFSET + n)
#define LOONGSON_INT_ROUTER_LPC		LOONGSON_INT_ROUTER_ENTRY(0x0a)
#define LOONGSON_INT_ROUTER_THM		LOONGSON_INT_ROUTER_ENTRY(0x0e)
#define LOONGSON_INT_ROUTER_HT1(n)	LOONGSON_INT_ROUTER_ENTRY(n + 0x18)

#define LOONGSON_INT_COREx_INTy(x, y)	(1<<(x) | 1<<(y+4))	/* route to int y of core x */

#define LS2H_PCH_IRQ_BASE		LOONGSON_PCH_IRQ_BASE
#define LS2H_PCH_ACPI_IRQ		(LS2H_PCH_IRQ_BASE + 0)
#define LS2H_PCH_HPET_IRQ		(LS2H_PCH_IRQ_BASE + 1)
#define LS2H_PCH_UART0_IRQ		(LS2H_PCH_IRQ_BASE + 2)
#define LS2H_PCH_UART1_IRQ		(LS2H_PCH_IRQ_BASE + 3)
#define LS2H_PCH_UART2_IRQ		(LS2H_PCH_IRQ_BASE + 4)
#define LS2H_PCH_UART3_IRQ		(LS2H_PCH_IRQ_BASE + 5)
#define LS2H_PCH_SPI_IRQ		(LS2H_PCH_IRQ_BASE + 6)
#define LS2H_PCH_I2C0_IRQ		(LS2H_PCH_IRQ_BASE + 7)
#define LS2H_PCH_I2C1_IRQ		(LS2H_PCH_IRQ_BASE + 8)
#define LS2H_PCH_AC97_IRQ		(LS2H_PCH_IRQ_BASE + 9)
#define LS2H_PCH_DMA0_IRQ		(LS2H_PCH_IRQ_BASE + 10)
#define LS2H_PCH_DMA1_IRQ		(LS2H_PCH_IRQ_BASE + 11)
#define LS2H_PCH_DMA2_IRQ		(LS2H_PCH_IRQ_BASE + 12)
#define LS2H_PCH_LPC_IRQ		(LS2H_PCH_IRQ_BASE + 13)
#define LS2H_PCH_RTC_INT0_IRQ		(LS2H_PCH_IRQ_BASE + 14)
#define LS2H_PCH_RTC_INT1_IRQ		(LS2H_PCH_IRQ_BASE + 15)
#define LS2H_PCH_RTC_INT2_IRQ		(LS2H_PCH_IRQ_BASE + 16)
#define LS2H_PCH_TOY_INT0_IRQ		(LS2H_PCH_IRQ_BASE + 17)
#define LS2H_PCH_TOY_INT1_IRQ		(LS2H_PCH_IRQ_BASE + 18)
#define LS2H_PCH_TOY_INT2_IRQ		(LS2H_PCH_IRQ_BASE + 19)
#define LS2H_PCH_RTC_TICK_IRQ		(LS2H_PCH_IRQ_BASE + 20)
#define LS2H_PCH_TOY_TICK_IRQ		(LS2H_PCH_IRQ_BASE + 21)
#define LS2H_PCH_NAND_IRQ		(LS2H_PCH_IRQ_BASE + 22)
#define LS2H_PCH_SYS_INTN_IRQ		(LS2H_PCH_IRQ_BASE + 23)
#define LS2H_PCH_EHCI_IRQ		(LS2H_PCH_IRQ_BASE + 32)
#define LS2H_PCH_OHCI_IRQ		(LS2H_PCH_IRQ_BASE + 33)
#define LS2H_PCH_OTG_IRQ		(LS2H_PCH_IRQ_BASE + 34)
#define LS2H_PCH_GMAC0_IRQ		(LS2H_PCH_IRQ_BASE + 35)
#define LS2H_PCH_GMAC1_IRQ		(LS2H_PCH_IRQ_BASE + 36)
#define LS2H_PCH_SATA_IRQ		(LS2H_PCH_IRQ_BASE + 37)
#define LS2H_PCH_GPU_IRQ		(LS2H_PCH_IRQ_BASE + 38)
#define LS2H_PCH_DC_IRQ			(LS2H_PCH_IRQ_BASE + 39)
#define LS2H_PCH_PWM0_IRQ		(LS2H_PCH_IRQ_BASE + 40)
#define LS2H_PCH_PWM1_IRQ		(LS2H_PCH_IRQ_BASE + 41)
#define LS2H_PCH_PWM2_IRQ		(LS2H_PCH_IRQ_BASE + 42)
#define LS2H_PCH_PWM3_IRQ		(LS2H_PCH_IRQ_BASE + 43)
#define LS2H_PCH_HT0_IRQ		(LS2H_PCH_IRQ_BASE + 44)
#define LS2H_PCH_HT1_IRQ		(LS2H_PCH_IRQ_BASE + 45)
#define LS2H_PCH_HT2_IRQ		(LS2H_PCH_IRQ_BASE + 46)
#define LS2H_PCH_HT3_IRQ		(LS2H_PCH_IRQ_BASE + 47)
#define LS2H_PCH_HT4_IRQ		(LS2H_PCH_IRQ_BASE + 48)
#define LS2H_PCH_HT5_IRQ		(LS2H_PCH_IRQ_BASE + 49)
#define LS2H_PCH_HT6_IRQ		(LS2H_PCH_IRQ_BASE + 50)
#define LS2H_PCH_HT7_IRQ		(LS2H_PCH_IRQ_BASE + 51)
#define LS2H_PCH_PCIE_PORT0_IRQ		(LS2H_PCH_IRQ_BASE + 52)
#define LS2H_PCH_PCIE_PORT1_IRQ		(LS2H_PCH_IRQ_BASE + 53)
#define LS2H_PCH_PCIE_PORT2_IRQ		(LS2H_PCH_IRQ_BASE + 54)
#define LS2H_PCH_PCIE_PORT3_IRQ		(LS2H_PCH_IRQ_BASE + 55)
#define LS2H_PCH_SATA_PHY_IRQ		(LS2H_PCH_IRQ_BASE + 56)
#define LS2H_PCH_HDA_IRQ		(LS2H_PCH_IRQ_BASE + 57)
#define LS2H_PCH_GPIO0_IRQ		(LS2H_PCH_IRQ_BASE + 64)
#define LS2H_PCH_GPIO1_IRQ		(LS2H_PCH_IRQ_BASE + 65)
#define LS2H_PCH_GPIO2_IRQ		(LS2H_PCH_IRQ_BASE + 66)
#define LS2H_PCH_GPIO3_IRQ		(LS2H_PCH_IRQ_BASE + 67)
#define LS2H_PCH_GPIO4_IRQ		(LS2H_PCH_IRQ_BASE + 68)
#define LS2H_PCH_GPIO5_IRQ		(LS2H_PCH_IRQ_BASE + 69)
#define LS2H_PCH_GPIO6_IRQ		(LS2H_PCH_IRQ_BASE + 70)
#define LS2H_PCH_GPIO7_IRQ		(LS2H_PCH_IRQ_BASE + 71)
#define LS2H_PCH_GPIO8_IRQ		(LS2H_PCH_IRQ_BASE + 72)
#define LS2H_PCH_GPIO9_IRQ		(LS2H_PCH_IRQ_BASE + 73)
#define LS2H_PCH_GPIO10_IRQ		(LS2H_PCH_IRQ_BASE + 74)
#define LS2H_PCH_GPIO11_IRQ		(LS2H_PCH_IRQ_BASE + 75)
#define LS2H_PCH_GPIO12_IRQ		(LS2H_PCH_IRQ_BASE + 76)
#define LS2H_PCH_GPIO13_IRQ		(LS2H_PCH_IRQ_BASE + 77)
#define LS2H_PCH_GPIO14_IRQ		(LS2H_PCH_IRQ_BASE + 78)
#define LS2H_PCH_GPIO15_IRQ		(LS2H_PCH_IRQ_BASE + 79)
#define LS2H_PCH_LAST_IRQ		(LS2H_PCH_IRQ_BASE + 160)

#define LS7A_PCH_IRQ_BASE		LOONGSON_PCH_IRQ_BASE
#define LS7A_PCH_UART0_IRQ		(LS7A_PCH_IRQ_BASE + 8)
#define LS7A_PCH_ACPI_IRQ		(LS7A_PCH_IRQ_BASE + 47)
#define LS7A_PCH_GUEST_ACPI_IRQ		(LS7A_PCH_IRQ_BASE + 4)
#define LS7A_PCH_HPET_IRQ		(LS7A_PCH_IRQ_BASE + 55)
#define LS7A_PCH_LAST_IRQ		(LS7A_PCH_IRQ_BASE + 63)

#define RS780_PCH_HPET_IRQ		0
#define RS780_PCH_ACPI_IRQ		7

#define GSI_MIN_LPC_IRQ		LOONGSON_LPC_IRQ_BASE
#define GSI_MAX_LPC_IRQ		LOONGSON_LPC_LAST_IRQ
#define GSI_MIN_MIPS_IRQ	MIPS_CPU_IRQ_BASE
#define GSI_MAX_MIPS_IRQ	(MIPS_CPU_IRQ_BASE + 7)
#define GSI_MIN_PCH_IRQ		LOONGSON_PCH_IRQ_BASE
#define GSI_MAX_PCH_IRQ		LOONGSON_PCH_LAST_IRQ
#define GSI_MIN_CPU_IRQ		16
#define GSI_MAX_CPU_IRQ		47

/*
 * Define pch I/O interrupt route model
 *
 **/
enum pch_irq_route_model_id {
	PCH_IRQ_ROUTE_LINE,	/* route to interrupt line on CPU legacy I/O interrupt controller*/
	PCH_IRQ_ROUTE_HT,	/* route to ht controller */
	PCH_IRQ_ROUTE_EXT,	/* route to CPU ext I/O interrupt controller through ht controller*/
	PCH_IRQ_ROUTE_EXT_GUEST,/* guest ext I/O interrupt controller*/
	PCH_IRQ_ROUTE_END
};
extern enum pch_irq_route_model_id pch_irq_route_model;

#define IPI_IRQ_OFFSET 6
#define MAX_IRQS  NR_IRQS
#define MAX_DIRQS (32 - 6)

extern unsigned int irq_cpu[MAX_IRQS];
extern unsigned int ipi_irq2pos[MAX_IRQS];
extern unsigned int ipi_pos2irq[MAX_DIRQS];

extern spinlock_t bitmap_lock;

int create_ipi_dirq(unsigned int irq);
void destroy_ipi_dirq(unsigned int irq);
int def_set_irq_affinity(struct irq_data *d, const struct cpumask *affinity, bool force);
int ext_set_irq_affinity(struct irq_data *d, const struct cpumask *affinity, bool force);

struct pch_pic_gsi {
	u32 gsi_base;
	u32 gsi_end;
};

extern u32 gsi_top;
struct pch_pic_config {
	unsigned char pch_pic_id;
	unsigned char pch_pic_ver;
	unsigned int pch_pic_addr;
};
/*
 * # of PCH_PICs and # of IRQ routing registers
 */
extern int nr_pch_pics;
extern int find_pch_pic(u32 gsi);
extern int pch_pic_id(int pch_pic);
extern unsigned long pch_pic_addr(int pch_pic);
extern struct pch_pic_gsi *pch_pic_gsi_routing(int pch_pic);
extern void __init register_pch_pic(int id, u64 address, u32 gsi);

extern struct irq_chip loongson_msi_irq_chip;
extern struct irq_chip loongson_vz_msi_irq_chip;

extern void fixup_irqs(void);
extern void vz_fixup_irqs(void);
extern void extioi_init(void);
extern void loongson3_ipi_interrupt(struct pt_regs *regs);
extern void loongson3_vz_ipi_interrupt(struct pt_regs *regs);
extern struct fwnode_handle *liointc_handle;
extern int liointc_init(int base_addr, struct fwnode_handle **handle);
extern int pch_msi_init(struct irq_domain *parent_domain, bool ext, int model);
extern int htvec_init(u64 base_addr, struct fwnode_handle *parent_handle, struct fwnode_handle **handle);
extern int extioi_vec_init(struct fwnode_handle **handle, int model);
extern int pch_lpc_init(struct fwnode_handle *domain_handle);
extern int pch_pic_init(u64 base_addr, struct fwnode_handle *parent_handle, int model,
		int gsi_base, struct device_node *node);
extern void handle_virq(unsigned int irq, unsigned int cpu);
#endif

#ifdef CONFIG_CPU_LOONGSON2K

#define MIPS_CPU_IRQ_BASE 		56
#define MIPS_CPU_LAST_IRQ 		(MIPS_CPU_IRQ_BASE + 7)
#define NR_IRQS				192
#define MAX_IRQS			NR_IRQS
#define LS2K_IRQ_BASE 			64
#define LS2K_MSI_IRQ_BASE 		128
#define LS2K_IRQ_LAST			(NR_IRQS - 1)

#endif

#include_next <irq.h>
#endif /* __ASM_MACH_LOONGSON64_IRQ_H_ */
