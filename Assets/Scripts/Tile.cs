using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tile
{
    public int[,] index;
    public Vector2 pos;

    public Tile(Vector2 pos){
        this.pos = pos;
    }
}
