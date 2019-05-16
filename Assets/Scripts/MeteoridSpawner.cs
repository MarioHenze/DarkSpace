using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MeteoridSpawner : MonoBehaviour
{
    public GameObject meteoridPrefab;
    public float spwanTimeMin;
    public float spawnTimeMax;
    [Tooltip("In seconds")]
    public float timeToImpact;

    private enum ObstacleType { Top, Bottom, Left, Right, Mid};

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
            switch ((ObstacleType)UnityEngine.Random.Range(0, Enum.GetNames(typeof(ObstacleType)).Length))
            {
                case ObstacleType.Top:
                    SpwanObject(new int[] { 0, 0});
                    SpwanObject(new int[] { 1, 0 });
                    SpwanObject(new int[] { 2, 0 });
                    SpwanObject(new int[] { 0, 1 });
                    SpwanObject(new int[] { 1, 1 });
                    SpwanObject(new int[] { 2, 1 });
                    break;
                case ObstacleType.Bottom:
                    SpwanObject(new int[] { 0, 2 });
                    SpwanObject(new int[] { 1, 2 });
                    SpwanObject(new int[] { 2, 2 });
                    SpwanObject(new int[] { 0, 1 });
                    SpwanObject(new int[] { 1, 1 });
                    SpwanObject(new int[] { 2, 1 });
                    break;
                case ObstacleType.Left:
                    SpwanObject(new int[] { 0, 0 });
                    SpwanObject(new int[] { 0, 1 });
                    SpwanObject(new int[] { 0, 2 });
                    SpwanObject(new int[] { 1, 0 });
                    SpwanObject(new int[] { 1, 1 });
                    SpwanObject(new int[] { 1, 2 });
                    break;
                case ObstacleType.Right:
                    SpwanObject(new int[] { 2, 0 });
                    SpwanObject(new int[] { 2, 1 });
                    SpwanObject(new int[] { 2, 2 });
                    SpwanObject(new int[] { 1, 0 });
                    SpwanObject(new int[] { 1, 1 });
                    SpwanObject(new int[] { 1, 2 });
                    break;
                case ObstacleType.Mid:
                    SpwanObject(new int[] { 1, 1 });
                    break;
            }

            //int[] index = new int[] { Random.Range(0, GameController.Instance.numRows), Random.Range(0, GameController.Instance.numRows) };
            //Vector3 pos = new Vector3(GameController.Instance.getTileAt(index).pos.x, GameController.Instance.getTileAt(index).pos.y, 10);
            //GameObject meteroid = Instantiate(meteoridPrefab, pos, Quaternion.identity);
            //meteroid.GetComponent<ObstcaleScript>().speed = 10/ timeToImpact;
            //meteroid.GetComponent<ObstcaleScript>().maxSize = 10/ GameController.Instance.numRows * 0.75f;

            nextMeteorid = UnityEngine.Random.Range(spwanTimeMin, spawnTimeMax);
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
