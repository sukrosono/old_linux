import os;
target= 'bad-sector-sda1.txt';
targetToTry= 'sample.txt';

counter=0;
with open(targetToTry, 'a+') as f:
  # print "old: "+ old;
  lines= f.readlines();
  old= list(lines);
  newLines= [];
  print "readlines: "+ "".join([str(i) for i in lines]);
  for i, line in enumerate(lines):
    print "i: ", i;
    if i>0:
      line+="\t\ttodo1"+ str(i*1)+ "\t\ttodo2"+ str(i*2);
    print line;
    newLines.append(line);
  f.seek(0);
  f.truncate();
  f.write(newLines);
  f.close();
  
