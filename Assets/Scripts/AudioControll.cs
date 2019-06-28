using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AudioControll : MonoBehaviour
{

    private GameObject player;
    //public GameObject obst;
    private Vector3 playerPosition;
    public Hv_heavy_AudioLib test;
    private float distanceX;
    private float distanceZ;

    public Hv_heavy_AudioLib.Parameter zPosToAudio;

    // Start is called before the first frame update
    void Start()
    {
        player = GameObject.Find("Player");
       //test.SetFloatParameter(Hv_heavy_AudioLib.Parameter.Metro, 200);
       //test.SetFloatParameter(Hv_heavy_AudioLib.Parameter.Tonone, 68);
       // test.SetFloatParameter(Hv_heavy_AudioLib.Parameter.Tontwo, 0);
       //test.SetFloatParameter(Hv_heavy_AudioLib.Parameter.Soundbar, 0.1f);

        Debug.Log(zPosToAudio);
        foreach(Hv_heavy_AudioLib.Parameter para in Enum.GetValues(typeof(Hv_heavy_AudioLib.Parameter)))
        {
            Debug.Log(para);
        }
    }

    // Update is called once per frame
    void Update()
    {
        distanceZ = Mathf.Abs(transform.position.z - player.GetComponent<Transform>().position.z);
        distanceX = Mathf.Abs(transform.position.x - player.GetComponent<Transform>().position.x);

        float distZFloat = distanceZ / 10; // 10 is the current z position where the obstacles start
        Debug.Log(distZFloat);

        //Debug.Log("X Abstand" + distanceX);
        //Debug.Log("z Abstand" + distanceZ);

        //Debug.Log("Metro" + test.GetFloatParameter(Hv_heavy_AudioLib.Parameter.Metro));
        
        
        test.SetFloatParameter(Hv_heavy_AudioLib.Parameter.Metro, distZFloat * 200);



        //if (distanceX <= 0.5f)
        //{
        //    Debug.Log("hallo");
        //    test.SetFloatParameter(Hv_heavy_AudioLib.Parameter.Soundbar, test.GetFloatParameter(Hv_heavy_AudioLib.Parameter.Soundbar) + 0.01f);
        //    //test.SendFloatToReceiver("soundBar", test.GetFloatParameter(Hv_heavy_AudioLib.Parameter.Soundbar) + 0.1f);
        //    Debug.Log("Soundbar" + test.GetFloatParameter(Hv_heavy_AudioLib.Parameter.Soundbar));

        //    test.SetFloatParameter(Hv_heavy_AudioLib.Parameter.Metro, test.GetFloatParameter(Hv_heavy_AudioLib.Parameter.Metro) - 1f);
        //    Debug.Log("Metronom" + test.GetFloatParameter(Hv_heavy_AudioLib.Parameter.Metro));

        //    test.SendFloatToReceiver("tonone", test.GetFloatParameter(Hv_heavy_AudioLib.Parameter.Tonone) + 1f);
        //}
        //else 
        //{
        //    test.SendFloatToReceiver("soundBar", 0.0f);

        //}

    }
}
