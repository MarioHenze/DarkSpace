using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ObstcaleScript : MonoBehaviour
{
    [HideInInspector]
    public float speed = 5f;
    public float maxSize = 3;
    public Material hitMaterial;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.position += new Vector3(0, 0, -speed * Time.deltaTime);
        float interpolation = 1 - transform.position.z / 10;
        float lerp = Mathf.Lerp(1, maxSize, interpolation);
        transform.localScale = new Vector3(lerp, lerp, 1);

        if (transform.position.z < 0)
        {
            GameObject.Destroy(gameObject);

            GameController.Instance.score++;
        }
    }

    public void Hit()
    {
        gameObject.GetComponentInChildren<Renderer>().material = hitMaterial;
        Debug.Log("GAME OVER");

        GameController.Instance.GameOver();
    }
}
