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

    float nextMeteorid;
    // Start is called before the first frame update
    void Start()
    {
        nextMeteorid = Random.Range(spwanTimeMin, spawnTimeMax);
    }

    // Update is called once per frame
    void Update()
    {
        nextMeteorid -= Time.deltaTime;

        // it's time for another obstacle!
        if (nextMeteorid <= 0)
        {
            int[] index = new int[] { Random.Range(0, GameController.Instance.numRows), Random.Range(0, GameController.Instance.numRows) };
            Vector3 pos = new Vector3(GameController.Instance.getTileAt(index).pos.x, GameController.Instance.getTileAt(index).pos.y, 10);
            GameObject meteroid = Instantiate(meteoridPrefab, pos, Quaternion.identity);
            meteroid.GetComponent<ObstcaleScript>().speed = 10/ timeToImpact;
            meteroid.GetComponent<ObstcaleScript>().maxSize = 10/ GameController.Instance.numRows * 0.75f;

            nextMeteorid = Random.Range(spwanTimeMin, spawnTimeMax);
        }
    }
}
