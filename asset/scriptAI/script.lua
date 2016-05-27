printV = function()
    return printMessage()
end

sumNumbers = function()
    return test.i + test.i
end

test = function()
    print("dans le lua\n")
    return 0
end

setpos = function(e)
  s = "In Lua : setDirection -> "
  print(e["test"])
  return math.random(1,4)
end

ai = function()
    move = {
      a = 2,
      b = 1
    }
    e = findPath()
    return setpos(e)
end
