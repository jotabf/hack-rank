set @i:=0;
select REPEAT('* ', @i:=@i+1) from information_schema.tables where @i < 20;