declare @result varchar(8000);
declare @i int, @j int, @isp int;
set @result = "2";
set @i = 3;

while @i <= 1000
begin
    set @j = 2;
    set @isp = 1;

    while @j <= floor(sqrt(@i)) and @isp = 1
    begin
        if @i % @j = 0 
            set @isp = 0;
        set @j = @j + 1;
    end    
    
    if @isp = 1     
        set @result += '&' + ltrim(str(@i));
    set @i = @i + 1;
end 

print @result