Fbox = 1
Fibox = 2
Fplayer = 3
Fpowerups = 4
Fsafe = 5

  -- table(success, size, dir(x,y), target(x,y))findPath(int player ,int flag);
  -- table(x,y) getPos(int numplayer);
  -- int getMood(int numplayer);
  -- void setMood(int numplayer, int moood);

ai = function(id)
    r = {
      bomb,
      move
    }
    r["bomb"] = 0
    r["move"] = 0
    if (iAmSafe(id) == 1) then
          retups = findPath(id, Fpowerups)
          r["move"] = retups["dir"]
          if retups["dir"] > 0 then
             if (directionIsSafe(id, retups["dir"]) == 1) then r["move"] = 0 end
          else
          ret = findPath(id, Fbox)
          r["move"] = ret["dir"]
          if (directionIsSafe(id, ret["dir"]) == 1) then
            r["move"] = 0 end
          if (ret["size"] == 0) then
            r["bomb"] = 1 end
          end
    else
       ret = findPath(id, Fsafe)
       r["move"] = ret["safedir"]
    end
    return r
end
