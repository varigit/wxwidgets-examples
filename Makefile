# =========================================================================
#     This makefile was generated by
#     Bakefile 0.2.13 (http://www.bakefile.org)
#     Do not modify, all changes will be overwritten!
# =========================================================================



# -------------------------------------------------------------------------
# These are configurable options:
# -------------------------------------------------------------------------



# -------------------------------------------------------------------------
# Do not modify the rest of this file!
# -------------------------------------------------------------------------

### Variables: ###


### Conditionally set variables: ###



### Targets: ###

all: CodeSamples wxDashBoard

install: 

uninstall: 

clean: 
	-(cd CodeSamples && $(MAKE) clean)
	-(cd wxdashboard && $(MAKE) clean)

CodeSamples: 
	(cd CodeSamples && $(MAKE) all)

wxDashBoard: 
	(cd wxdashboard && $(MAKE) all)

.PHONY: all install uninstall clean CodeSamples wxDashBoard


# Dependencies tracking:
-include ./*.d