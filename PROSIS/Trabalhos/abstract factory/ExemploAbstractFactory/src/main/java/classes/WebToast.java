/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package classes;

import interfaces.Toast;
import java.awt.BorderLayout;
import java.awt.Color;
import java.util.Timer;
import java.util.TimerTask;
import javax.swing.JLabel;
import javax.swing.JWindow;
import javax.swing.SwingConstants;

/**
 *
 * @author lucas
 */
public class WebToast implements Toast{

    @Override
    public void mostrar(String mensagem) {
        JWindow toastWindow = new JWindow();
        toastWindow.setLayout(new BorderLayout());
        toastWindow.setSize(300, 50);
        toastWindow.setLocationRelativeTo(null);

        JLabel label = new JLabel(mensagem, SwingConstants.CENTER);
        label.setOpaque(true);
        label.setBackground(Color.DARK_GRAY);
        label.setForeground(Color.WHITE);
        toastWindow.add(label, BorderLayout.CENTER);

        toastWindow.setVisible(true);

        new Timer().schedule(new TimerTask() {
            @Override
            public void run() {
                toastWindow.setVisible(false);
                toastWindow.dispose();
            }
        }, 2000);
    }
    
}
