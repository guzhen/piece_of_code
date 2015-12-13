data=File.new(ARGV[0]).read().force_encoding('utf-8')
style=Regexp.new('^Style:\s+[^,]+,([^,]+),')
script=Regexp.new('{[^}]*\\\\fn([^}\\\\]+)[^}]*}')
f1=data.scan(style).flatten.uniq
f2=data.scan(script).flatten.uniq
File.new(ARGV[0]+"_font.txt",'w').write((f1+f2).uniq.join("\n"))
