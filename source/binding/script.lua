Fbox = 1
Fibox = 2
Fplayer = 3

  -- table(success, size, dir(x,y), target(x,y))findPath(int player ,int flag);
  -- table(x,y) getPos(int numplayer);
  -- int getMood(int numplayer);
  -- void setMood(int numplayer, int moood);

ai = function(id)
    r = {
      bomb,
      move
    }
    e = findPath(id, 1)
    a = e["success"]
    r["bomb"] = 0
    r["move"] = 0
    if a == 2 then
--      print("safesoze dir : " .. e["safedir"])
      r["bomb"] = 0
      r["move"] = e["safedir"]
      return r
    else
--      print("dir " .. e["dir"] .. " size " .. e["size"])
      r["bomb"] = 0
      r["move"] = 0 --e["dir"]
      return r
    end
  return r
end
