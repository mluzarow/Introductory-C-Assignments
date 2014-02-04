fid = fopen('labData','r'); %open data file
if (fid ~= -1) %check for proper opening of data file
  while (~feof(fid)) %check for end of file
    var1 = fscanf(fid,'%d',1);%read the first value from file
    var2 = fscanf(fid,'%d',1);%read second value from file
    if (~feof(fid)) %determine if at the end of the file
      fprintf('\n\nPrime numbers in the range [%d, %d]:\n\n', var1, var2);
      prime1 = 0; %first saved value of prime numbers
      prime2 = 0; %second saved value of prime numbers
      while (var1 <= var2)
        count = 3; %count to be incrimented to mod numbers
        output = 0; %set numbers to prime automatically
        if ((mod(var1, 2) == 0) && (var1 ~= 2)) %check for even values
          output = 1;
        elseif (((mod(var1, count) == 0) && (var1 ~= 2) && (var1 ~= 3))||  var1 == 1)
          output = 1;
        else
          while (count <= sqrt(var1))
            if (mod(var1, count) == 0)
              output = 1;
            end
            count = count + 2;
          end
        end
        if (output == 0)
          if(((prime2 + var1) / 2 == prime1) && (prime1 ~= 0) && (prime2 ~= 0))
            fprintf(' is a balanced prime.\n');
          elseif(((prime2 + var1) / 2 < prime1) && (prime1 ~= 0) && (prime2 ~= 0))
            fprintf(' is a strong prime.\n');
          elseif((prime1 ~= 0) && (prime2 ~= 0))
            fprintf(' is a weak prime.\n');
          end
          if (prime1 == 0)
            fprintf('%d\n', var1);
          else
            fprintf('%d', var1);
          end
          prime2 = prime1;%update variables
          prime1 = var1;%update variables
        end
        var1 = var1 + 1; %incriment variable
      end
    end
  end
  fclose(fid); %close read file
else
  fprintf('\n\nERROR OPENING FILE FOR READING\n\n');
end