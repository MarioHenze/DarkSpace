﻿using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

[CustomEditor(typeof(SpawnPoint))]
public class SpawnPointtEditor : Editor
{
    SpawnPoint myTarget;
    int currentNumRows;
    int currentNumCols;

    private void Awake()
    {
        myTarget = (SpawnPoint)target;
        currentNumRows = myTarget.numRows;
        currentNumCols = myTarget.numColumns;
    }

    public override void OnInspectorGUI()
    {
        myTarget.numRows = EditorGUILayout.IntField("numRows", myTarget.numRows);
        myTarget.numColumns = EditorGUILayout.IntField("numCols", myTarget.numColumns);
        EditorGUILayout.Space();
        EditorGUILayout.LabelField("Select Cells");
        
        if (myTarget.numRows != currentNumRows || myTarget.numColumns != currentNumCols)
        {
            OnSizeChanged();
        }

        GUILayoutUtility.GetRect(50, myTarget.numRows * 50 + 30);

        for (int i = 0; i < myTarget.numColumns; i++)
        {
            for (int j = 0; j < myTarget.numRows; j++)
            {
                //myTarget.tiles[j * myTarget.numColumns + i] = EditorGUI.Toggle(new Rect(20 + 30 * i, 70 + 30 * j, 20, 20), myTarget.tiles[j * myTarget.numColumns + i]);
                if(GUI.Button(new Rect(20 + 50 * i, 70 + 50 * j, 50, 50), myTarget.tiles[j * myTarget.numColumns + i] ? "X" : ""))
                {
                    OnButtonToggle(i,j);
                }
            }
        }
    }

    [ExecuteInEditMode]
    void OnSizeChanged()
    {
        if (myTarget.numRows < 1)
            myTarget.numRows = 1;

        if (myTarget.numColumns < 1)
            myTarget.numColumns = 1;

        currentNumRows = myTarget.numRows;
        currentNumCols = myTarget.numColumns;

        myTarget.tiles = new bool[currentNumRows * currentNumCols];

        EditorUtility.SetDirty(myTarget);
    }

    [ExecuteInEditMode]
    void OnButtonToggle(int x , int y)
    {
        myTarget.tiles[y * myTarget.numColumns + x] = !myTarget.tiles[y * myTarget.numColumns + x];
        EditorUtility.SetDirty(myTarget);
    }

}
