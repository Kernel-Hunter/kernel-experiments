/*
 * hello_kmod.c - Example kernel module that creates a /proc/hello_kmod entry.
 *
 * Build with the provided Makefile (make).
 *
 * Safety:
 * - For educational/demo use only.
 * - Load only in VMs or test machines.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

#define PROC_NAME "hello_kmod"
#define HELLO_MSG "Hello from hello_kmod!\n"

static struct proc_dir_entry *proc_entry;

static ssize_t hello_read(struct file *file, char __user *buf,
                          size_t count, loff_t *ppos)
{
    return simple_read_from_buffer(buf, count, ppos, HELLO_MSG, strlen(HELLO_MSG));
}

static const struct proc_ops proc_file_ops = {
    .proc_read = hello_read,
};

static int __init hello_init(void)
{
    proc_entry = proc_create(PROC_NAME, 0444, NULL, &proc_file_ops);
    if (!proc_entry) {
        pr_err("hello_kmod: failed to create /proc/%s\n", PROC_NAME);
        return -ENOMEM;
    }
    pr_info("hello_kmod: loaded\n");
    return 0;
}

static void __exit hello_exit(void)
{
    proc_remove(proc_entry);
    pr_info("hello_kmod: unloaded\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Karim Masmoudi <replace-with-email@example.com>");
MODULE_DESCRIPTION("Example kernel module: /proc/hello_kmod");
MODULE_VERSION("0.1");

module_init(hello_init);
module_exit(hello_exit);