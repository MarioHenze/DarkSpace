﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameController : MonoBehaviour
{

    private static GameController _instance;
    public static GameController Instance { get { return _instance; } }

    [Tooltip("Number of rows and columns")]
    public int numRows = 3; //number of rows
    Tile[,] tiles;

    int[] playerTile = new int[2];

    public int score = 0;

    [ExecuteInEditMode]
    void OnValidate()
    {
        if(numRows % 2 == 0)
        numRows += 1;
    }

    void Awake()
    {
        if (_instance != null && _instance != this)
        {
            Destroy(this.gameObject);
        }
        else
        {
            _instance = this;
            DontDestroyOnLoad(this.gameObject);
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        tiles = new Tile[numRows, numRows];
        float tileSize = 10f / numRows;
        //make a grid
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < numRows; j++)
            {
                //do something for every tile
                //TODO these numbers shouldn't be hardcoded maybe
                tiles[i, j] = new Tile(new Vector2( - 5 + tileSize/2 + tileSize * i, 5 - tileSize/2 - tileSize * j));
            }
        }

        //put the ship in the middle
        int middleTile = numRows / 2;
        playerTile = new int[] { middleTile, middleTile};
        MoveTo(new int[] { middleTile, middleTile});

    }

    // Update is called once per frame
    void Update()
    {
        if (isOver)
        {
            if (Input.GetKey(KeyCode.Space))
            {
                Reset();
                return;
            }
        }

        if (Input.GetKey(KeyCode.RightArrow))
        {

            int[] newTile = { 2, 1 };
            MoveTo(newTile);
        }

        else if (Input.GetKey(KeyCode.LeftArrow))
        {
            int[] newTile = { 0, 1 };
            MoveTo(newTile);
        }

        else if (Input.GetKey(KeyCode.UpArrow))
        {
            //int[] newTile = { 1, 0 };
            //MoveTo(newTile);
        }

        else if (Input.GetKey(KeyCode.DownArrow))
        {
            //int[] newTile = { 1, 2 };
            //MoveTo(newTile);
        }
        else
        {
            int[] newTile = { 1, 1 };
            MoveTo(newTile);
        }
    }

    public Tile getTileAt(int[] index)
    {
        return tiles[index[0], index[1]];
    }

    void MoveTo(int[] tile)
    {
        tile[0] = Mathf.Clamp(tile[0], 0, numRows - 1);
        tile[1] = Mathf.Clamp(tile[1], 0, numRows - 1);
        playerTile = tile;

        Transform player = PlayerController.Instance.gameObject.transform;

        StartCoroutine(AnimationController.Instance.MoveTo(player, player.position, tiles[playerTile[0], playerTile[1]].pos, .2f));
    }

    bool isOver;

    public void GameOver() {
        isOver = true;
        PlayerController.Instance.gameObject.SetActive(false);
        SceneManager.LoadScene("GameOver");
    }

    void Reset()
    {
        isOver = false;
        score = 0;
        PlayerController.Instance.gameObject.SetActive(true);
        SceneManager.LoadScene("MainScene");
    }
}
