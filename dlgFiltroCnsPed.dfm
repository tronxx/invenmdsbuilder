object frmDlgFilPedidos: TfrmDlgFilPedidos
  Left = 326
  Top = 202
  BorderStyle = bsDialog
  Caption = 'Filtro Pedidos'
  ClientHeight = 277
  ClientWidth = 345
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object RzPanel1: TPanel
    Left = 2
    Top = 6
    Width = 336
    Height = 214
    TabOrder = 0
    object RzLabel1: TLabel
      Left = 64
      Top = 16
      Width = 56
      Height = 13
      Caption = '&Primer Pedi.'
      FocusControl = edtPriPed
    end
    object RzLabel2: TLabel
      Left = 196
      Top = 16
      Width = 56
      Height = 13
      Caption = 'Ultimo Pedi.'
    end
    object RzLabel3: TLabel
      Left = 33
      Top = 88
      Width = 60
      Height = 13
      Caption = 'Fec&ha Inicial'
      FocusControl = dtFechaIni
    end
    object RzLabel4: TLabel
      Left = 228
      Top = 88
      Width = 55
      Height = 13
      Caption = 'Fecha Final'
    end
    object RzLabel5: TLabel
      Left = 20
      Top = 152
      Width = 79
      Height = 13
      Caption = 'Clave Pro&veedor'
      FocusControl = edtProve
    end
    object RzLabel6: TLabel
      Left = 194
      Top = 151
      Width = 18
      Height = 16
      Caption = 'F4'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object edtPriPed: TdxCurrencyEdit
      Left = 64
      Top = 32
      Width = 80
      TabOrder = 0
      DisplayFormat = '0;(0)'
      StoredValues = 0
    end
    object edtUltPed: TdxCurrencyEdit
      Left = 195
      Top = 32
      Width = 80
      TabOrder = 1
      DisplayFormat = '0;(0)'
      StoredValues = 0
    end
    object chkRangoFecha: TCheckBox
      Left = 110
      Top = 71
      Width = 115
      Height = 17
      Caption = 'Con Ra&ngo Fechas'
      TabOrder = 2
      OnClick = chkRangoFechaClick
    end
    object dtFechaIni: TDateTimePicker
      Left = 16
      Top = 104
      Width = 97
      Height = 21
      CalAlignment = dtaLeft
      Date = 38632.7792636574
      Time = 38632.7792636574
      DateFormat = dfShort
      DateMode = dmComboBox
      Enabled = False
      Kind = dtkDate
      ParseInput = False
      TabOrder = 3
    end
    object dtFechaFin: TDateTimePicker
      Left = 216
      Top = 104
      Width = 97
      Height = 21
      CalAlignment = dtaLeft
      Date = 38632.7792636574
      Time = 38632.7792636574
      DateFormat = dfShort
      DateMode = dmComboBox
      Enabled = False
      Kind = dtkDate
      ParseInput = False
      TabOrder = 4
    end
    object edtProve: TEdit
      Left = 104
      Top = 149
      Width = 85
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 4
      TabOrder = 5
      OnKeyDown = edtProveKeyDown
    end
    object edtNomProve: TEdit
      Left = 4
      Top = 177
      Width = 328
      Height = 21
      TabStop = False
      ReadOnly = True
      TabOrder = 6
    end
  end
  object btnAceptar: TBitBtn
    Left = 144
    Top = 235
    Width = 90
    Height = 30
    Caption = '&Aceptar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = btnAceptarClick
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      0400000000000001000000000000000000001000000010000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00666666666666
      66666666666666666666666666666666666666666666666666666666AC666666
      66666666F86666666666666A22C666666666666F88866666666666A2222C6666
      666666F88888666666666A222222C66666666F888888866666666A22CA222C66
      66666F888F88886666666A2C66A222C666666F8866F8888666666AC6666A222C
      66666F86666F8888666666666666A222C66666666666F8888666666666666A22
      2C66666666666F8888666666666666A222C66666666666F8888666666666666A
      22C666666666666F8886666666666666A2C6666666666666F886666666666666
      6AC66666666666666F8666666666666666666666666666666666}
    NumGlyphs = 2
  end
  object btnCerrar: TBitBtn
    Left = 247
    Top = 235
    Width = 90
    Height = 30
    Caption = '&Cerrar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = btnCerrarClick
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      0400000000000001000000000000000000001000000010000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00666666666666
      6666666666666666666666666666666666666666666666666666666666666666
      6666666666666666666669000666669000666F88866666F88866691110666911
      10666F8888666F888866669111069111066666F88886F8888666666911101110
      6666666F88888888666666669111110666666666F88888866666666669111066
      666666666F888866666666669111110666666666F88888866666666911101110
      6666666F888888886666669111069111066666F88886F8888666691110666911
      10666F8888666F88886669999666669999666FFFF66666FFFF66666666666666
      6666666666666666666666666666666666666666666666666666}
    NumGlyphs = 2
  end
  object qsProve: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'SELECT * FROM PROVEEDOR WHERE CODIGO = :codigo and Cia = :Cia')
    Left = 262
    Top = 87
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'Codigo'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
end
