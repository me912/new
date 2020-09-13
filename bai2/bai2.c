#include <linux/kernel.h> 
#include <linux/module.h> 
#include <linux/sched.h> 
#include <linux/workqueue.h> 
#include <linux/interrupt.h>


/* Day la ham xu ly ngat can duoc dang ki vao duong ngat danh cho ban phim */
irqreturn_t irq_handler(int irq, void * dev_id, struct pt_regs * regs) 
{  
    /*     * * This variables are static because they need to be     * * accessible (through pointers) to the bottom half routine.     * */  
    static unsigned char scancode;  
    unsigned char status;  
    /*    * * Read keyboard status    * */  
    status = inb(0x64);  
    scancode = inb(0x60);  
    switch (scancode) {  
        case 0x01:  
            printk(KERN_EMERG "! You pressed Esc ...\n");  
            break;  
        case 0x3B:  
            printk(KERN_EMERG "! You pressed F1 ...\n");  
            break;  
        case 0x3C:  
            printk(KERN_EMERG "! You pressed F2 ...\n");  
            break;  
        default:  
            break;  
    }  
    return IRQ_HANDLED;  
}  

/* * * Khoi tao module – Dang ki ham xu ly ngat * */  
static int __init irq_ex_init(void)
{  
    /* Dang ki ham xu ly ngat irq_handler duong ngat IRQ 1 la duong ngat cua ban phim */  
    int ret;  
    ret = request_irq(1, (irq_handler_t) irq_handler, IRQF_SHARED, "test_keyboard_irq_handler", (void * )(irq_handler));  
    
    if (ret) printk(KERN_EMERG "Cant init test_keyboard_irq_handler\n");  
        return ret;  
} 
 
/* * * Thoat module – Giai phong ham xu ly ngat * */  
static void __exit irq_ex_exit(void) {  
    printk(KERN_INFO "! Module is unload... \n");  
    free_irq(1, (void * )(irq_handler));  
}  

MODULE_LICENSE("GPL");  
module_init(irq_ex_init);  
module_exit(irq_ex_exit);
