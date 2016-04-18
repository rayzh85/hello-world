# Top Makefile                                                                                                                                                            
#
# Ray.Zh 2015-12-22
#

M_DIR = modules
MODULES = $(shell ls $(M_DIR))

all : $(MODULES)
 
$(MODULES):
	$(MAKE) -C $(M_DIR)/$@
 
clean : $(MODULES_CLEAN)
	for subdir in $(MODULES); do $(MAKE) -C $(M_DIR)/$$subdir $@; done

show:
	@echo $(MODULES)

help:
	@echo "===============Sample Codes=============================="
	@echo "Copyright xx.xx.xx.xx Corp"

	@echo "PLEASE SPECIFY YOUR <LINUX_DIR> IN mk.rule BEFORE COMPILE"

	@echo "The following targets aresupport:"
	@echo
	@echo " all              - (==make) compile and link"
	@echo " clean            - clean target"
	@echo " help             - print help information"
	@echo " show             - show all modules"
	@echo
	@echo "To make a target, do 'make [target]'"
	@echo "========================= Version0.1 ======================="

.PHONY : all clean help
