size = 2000 
macierzA = Array.new(size) { Array.new(size) }
macierzB = Array.new(size) { Array.new(size) }
macierzC = Array.new(size) { Array.new(size) }

start = Time.now

for i in 0..(size-1)
	for j in 0..(size-1)
		macierzA[i][j] = rand(50) 
		macierzB[i][j] = rand(50)
		macierzC[i][j] = 0
	end
end

                                        
for i in 0..(size-1)
	for j in 0..(size-1)
		for k in 0..(size-1)
			macierzC[i][j] += macierzA[i][k] * macierzB[k][j]
		end
	end
end                          

#def print
#	for i in 0..(size-1)
#		for j in 0..(size-1)
#			print "#{macierzA[i][j]} "  
#		end
#		puts ""
#	end
#	for i in 0..(size-1)
#		for j in 0..(size-1)
#			print "#{macierzB[i][j]} "  
#		end
#		puts ""
#	end
#	for i in 0..(size-1)
#		for j in 0..(size-1)
#			print "#{macierzC[i][j]} "  
#		end
#		puts ""
#	end
#end

end_ = Time.now
diff = end_ - start
diff = diff.round

puts "Czas wykonywania: #{diff} sekund"
