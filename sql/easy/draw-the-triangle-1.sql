set @i:=20;
select REPEAT('* ', @i:=@i-1) from information_schema.tables;