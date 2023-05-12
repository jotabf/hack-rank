SELECT round(AVG(lat_n), 4) as median
FROM (
  SELECT lat_n, @rownum:=@rownum+1 as `row_number`, @total_rows:=@rownum
  FROM (
    SELECT lat_n
    FROM station
    ORDER BY lat_n
  ) as sorted_values, (SELECT @rownum:=0) as t
) as numbered_values
WHERE 1
  AND `row_number` = FLOOR((@total_rows+1)/2)
  OR `row_number` = CEIL((@total_rows+1)/2)