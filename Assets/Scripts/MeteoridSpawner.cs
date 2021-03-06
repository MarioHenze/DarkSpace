﻿using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class MeteoridSpawner : MonoBehaviour
{
    public GameObject meteoridPrefab;
    public float spwanTimeMin;
    public float spawnTimeMax;
    [Tooltip("In seconds")]
    public float timeToImpact;

    //private enum ObstacleType { Top, Bottom, Left, Right, Mid, Around};
    private enum ObstacleType { Left, Right, Mid, Around };
    public List<SpawnPoint> spawnPoints;

    [ExecuteInEditMode]
    void OnValidate()
    {
        List<SpawnPoint> markedForDeletion = new List<SpawnPoint>();

        spawnPoints = new List<SpawnPoint>(spawnPoints.Distinct());
        foreach (SpawnPoint sp in spawnPoints)
        {
            if (sp.numRows != GameObject.FindObjectOfType<GameController>().numRows)
            {
                markedForDeletion.Add(sp);
            }
        }

        foreach(SpawnPoint sp in markedForDeletion)
        {
            spawnPoints.Remove(sp);
        }
    }

    float nextMeteorid;
    // Start is called before the first frame update
    void Start()
    {
        nextMeteorid = UnityEngine.Random.Range(spwanTimeMin, spawnTimeMax);
    }

    // Update is called once per frame
    void Update()
    {
        nextMeteorid -= Time.deltaTime;

        // it's time for another obstacle!
        if (nextMeteorid <= 0)
        {
            SpawnPoint sp = spawnPoints[UnityEngine.Random.Range(0, spawnPoints.Count)];
            for (int i = 0; i < GameController.Instance.numRows; i++)
            {
                for (int j = 0; j < GameController.Instance.numRows; j++)
                {
                    if(sp.tiles[j * 3 + i] == true)
                    {
                        SpwanObject(new int[] { i, j });
                    }
                }
            }

            //int[] index = new int[] { Random.Range(0, GameController.Instance.numRows), Random.Range(0, GameController.Instance.numRows) };
            //Vector3 pos = new Vector3(GameController.Instance.getTileAt(index).pos.x, GameController.Instance.getTileAt(index).pos.y, 10);
            //GameObject meteroid = Instantiate(meteoridPrefab, pos, Quaternion.identity);
            //meteroid.GetComponent<ObstcaleScript>().speed = 10/ timeToImpact;
            //meteroid.GetComponent<ObstcaleScript>().maxSize = 10/ GameController.Instance.numRows * 0.75f;

            nextMeteorid = UnityEngine.Random.Range(spwanTimeMin, spawnTimeMax);
            spwanTimeMin = Mathf.Clamp(spwanTimeMin - .25f, 1, 10);
            spawnTimeMax = Mathf.Clamp(spawnTimeMax - .25f, 1, 10);
            timeToImpact = Mathf.Clamp(timeToImpact - .25f, 1, 10);
        }
    }

    void SpwanObject(int[] index)
    {
        Vector3 pos = new Vector3(GameController.Instance.getTileAt(index).pos.x, GameController.Instance.getTileAt(index).pos.y, 10);
        GameObject meteroid = Instantiate(meteoridPrefab, pos, Quaternion.identity);
        meteroid.GetComponent<ObstcaleScript>().speed = 10 / timeToImpact;
        meteroid.GetComponent<ObstcaleScript>().maxSize = 10 / GameController.Instance.numRows * 0.75f;
    }
}
