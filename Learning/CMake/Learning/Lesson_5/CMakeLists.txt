cmake_minimum_required(VERSION 3.0.0)

set(VAR a)
# add them chu a vao VAR cho den khi nao = "aaaaa" thi dung
while(NOT VAR STREQUAL "aaaaa")
	set(VAR ${VAR}a)
endwhile()

message(${VAR})

# loop 3 name alice bob and charlie
foreach(Name Alice Bob Charlie)
	message(${Name})
endforeach()

# loop x tu` 100 den 105
foreach(x RANGE 100 105)
	message("Person_${x}")
endforeach()

# dau ; trong set() duoc hieu de tach nhung phan tu cua list
set(VAR1 0;1)
set(VAR2 2 3)
set(VAR3 "4 5")

# loop tung phan tu cua list VAR1 VAR2 va VAR3
foreach(x IN LISTS VAR1 VAR2 VAR3)
	message("x = ${x}")
endforeach()

# Khai bao function voi input la name_var
function(print_detail name_var)
	message("My name is ${name_var}")
	
	# truong hop optional argument, new truyen vao nhieu hon 1 vien name_var
	# phan tu dau tien se la ARGV0
	# neu thay doi gia tri cua variable trong function thi bien se chi bi thay doi trong function thoi
	# ra ngoai function bien se chuyen ve gia tri nhu luc truyen vao
	if(DEFINED ARGV1)
		message("Hello, my name is ${ARGV1}")
	endif()
endfunction()

# goi function voi bien truyen vao la "Dang"
#print_detail(Dang Duc)
print_detail(Dang)
