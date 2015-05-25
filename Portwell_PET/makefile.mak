# Sample makefile

#INCLUDES = "/IC:/Java60/include" "/IC:/Java60/include/win32"
INCLUDES =
#LIBS = User32.Lib ../xfs.sdk/msxfs.lib
LIBS =

CPP = cl.exe 
CPPFLAGS =/c /MD /EHsc /Zi /D_WIN32_WCE $(INCLUDES)
LN = link.exe /DEBUG /SUBSYSTEM:windows /MACHINE:X86 /INCREMENTAL:NO
RC = rc.exe 
RFLAGS = $(INCLUDES) /fo $@

BUILD = Portwell_PET
TARGET = $(BUILD).exe
SRCS = Portwell_PET.cpp PET.cpp Test.cpp
OBJS = $(SRCS:.cpp=.obj)

all: clean $(TARGET)
  
$(TARGET): $(OBJS) $(BUILD).res
  $(LN) /OUT:$(TARGET) $(BUILD).res /DEF:$(BUILD).def $(OBJS) $(LIBS)
  
#Implicit rules	
.cpp.obj:
	$(CPP) $(CPPFLAGS) $<

$(BUILD).res:
	$(RC) $(RFLAGS) $(BUILD).rc	

clean:
    del *.obj *.lib *.exp *.dll *.res *.pdb *.ilk *.exe
    echo $(USERNAME)