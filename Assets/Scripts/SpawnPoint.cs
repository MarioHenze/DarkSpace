using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnPoint : MonoBehaviour
{
    public int numRows = 3;
    public int numColumns = 3;
    public bool[] tiles = new bool[9];

    [ExecuteInEditMode]
    void OnValidate()
    {
        //Debug.Log("TEST" + numRows);
        //tiles = new bool[numRows * numColumns];
    }

}
