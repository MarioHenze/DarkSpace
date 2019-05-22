using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

[CustomEditor(typeof(SpawnPoint))]
public class SpawnPointtEditor : Editor
{
    SpawnPoint myTarget;
    private void Awake()
    {
        myTarget = (SpawnPoint)target;
        //myTarget.tiles = new bool[9];
    }

    public override void OnInspectorGUI()
    {
        if (GUI.changed == true)
            OnValidate();

            EditorGUILayout.LabelField("Select Cells");
        myTarget.numRows = EditorGUILayout.IntField("numRows", myTarget.numRows);
        myTarget.numColumns = EditorGUILayout.IntField("numCols", myTarget.numColumns);

        GUILayoutUtility.GetRect(50, 3 * 30 + 30);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                myTarget.tiles[j * 3 + i] = EditorGUI.Toggle(new Rect(20 + 30 * i, 70 + 30 * j, 20, 20), myTarget.tiles[j * 3 + i]);
            }
        }
    }

    [ExecuteInEditMode]
    void OnValidate()
    {
        //Debug.Log("TEST");
        //tiles = new bool[numRows * numColumns];
    }

}
