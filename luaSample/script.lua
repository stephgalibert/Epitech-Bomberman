printV = function()
    return printMessage()
end

sumNumbers = function()
    return test.i + test.i
end

setpos = function(e)
  s = "In Lua : setDirection -> "
  if e % 2 == 0
  then
     print(s, "WEST")
  else
     print(s, "NORTH")
  end
  return 0
end

ai = function()
    move = {
      a = 2,
      b = 1
    }
    s = "In Lua :"
    e = getpos()
    setpos(e)
    return move
end
