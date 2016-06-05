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
          retbox = findPath(id, Fbox)
          retsafe = findPath(id, Fsafe)
          r["move"] = retups["dir"]
          if retups["dir"] > 0  and retups["size"] < 5 then
            if (directionIsSafe(id, retups["dir"]) == 1) then r["move"] = 0 end
          else
            r["move"] = retbox["dir"]
          if (directionIsSafe(id, retbox["dir"]) == 1) then r["move"] = 0 end
          if (retbox["size"] == 0) then r["bomb"] = 1 end
          end
    else
       ret = findPath(id, Fsafe)
       r["move"] = ret["safedir"]
    end
    return r
end
