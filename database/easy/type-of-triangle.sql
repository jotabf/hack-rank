select 
  case 
    when a + b <= c or a + c <= b or b + c <= a then 'Not A Triangle'
    when a = b and a = c then 'Equilateral'
    when a <> b and a <> c then 'Scalene'
    else  'Isosceles'
  end
from triangles;