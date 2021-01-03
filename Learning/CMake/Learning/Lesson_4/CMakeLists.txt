cmake_minimum_required(VERSION 3.0.0)

#YES hoac NO la bien constant tuong ung voi true hoac false
set(VAR YES)

if(VAR)
	message("If block executed")
else()
	message("Else block executed")
endif()

set(Name Alice)
# Xem bien ${Name} da duoc define hay chua
if(DEFINED Name)
	message("Name: if block executed")
else()
	message("Name: else block executed")
endif()

# Check lenh target_link_libary co duoc chay chua
if(COMMAND target_link_library)
	message("target_link_library executed")
else()
	message("target_link_library not executed")
endif() 


set(Name1 Dang)
set(Name2 Duc)

# string compare
if(Name1 STRLESS Name2)
	message("${Name1} is less than ${Name2}")
elseif(Name1 STRGREATER Name2)
	message("${Name1} is greater than ${Name2}")
elseif(Name1 STREQUAL Name2)
	message("${Name1} is equal to ${Name2}")
endif()
