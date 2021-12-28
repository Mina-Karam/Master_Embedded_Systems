.global reset @@ global to all file see it

reset:
	ldr sp, = stack_top @@ From the linker @@0x00011000 @@ load form register
	bl main						@@ branch lable 

@@if there is no while (1) in main we need to get loop
stop:
	b stop