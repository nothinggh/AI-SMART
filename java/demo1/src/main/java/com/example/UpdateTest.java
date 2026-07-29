package com.example;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class UpdateTest {
    public static void main(String[] args) throws SQLException {
        String url = "jdbc:sqlite:data/study.db";
        String sql = "UPDATE book SET price = ? WHERE book_id = ?";

        try (Connection con = DriverManager.getConnection(url);
                PreparedStatement ps = con.prepareStatement(sql)) {
            ps.setInt(1, 15000);
            ps.setInt(2, 1);
            int count = ps.executeUpdate();
            System.out.println(count + "권 수정");
        }
    }
}
