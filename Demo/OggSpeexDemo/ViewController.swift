//
//  ViewController.swift
//  OggSpeexDemo
//
//  Created by Ryan on 2024/9/10.
//

import UIKit
import LBSpeex

class ViewController: UIViewController {

    private let player = LBPlayerManager()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        
    }

    @IBAction func actionClick(_ sender: Any) {
        play()
    }
    
    private func play() {
        if let path = Bundle.main.path(forResource: "hello", ofType: "spx") {
            player.play(path)
        }
    }
    
}

